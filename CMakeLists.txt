cmake_minimum_required(VERSION 3.8)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    message(STATUS "Found ccache package... Activating...")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif ()

if (DEFINED CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: Debug, Release, RelWithDebInfo")
else ()
    set (CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: Debug, Release, RelWithDebInfo")
endif ()

string(TOLOWER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_LOWER)

set(CMAKE_CONFIGURATION_TYPES Debug RelWithDebInfo Release CACHE TYPE INTERNAL)
set(ARCH native CACHE STRING "CPU to build for: -march value or native")

project(Adon)

enable_language(C)
enable_language(CXX)

# Assert our compiler is good
# if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     # GCC 7.0 or higher
#     if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7)
#         message(FATAL_ERROR "GCC/G++ 7.0 or greater is required to compile. Please check the README.md for detailed compilation instructions.")
#     endif ()
# elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#     # Clang 6.0 or higher
#     if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 6)
#         message(FATAL_ERROR "Clang 6.0 or greater is required to compile. Please check the README.md for detailed compilation instructions.")
#     endif ()
# elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#     # Visual Studio 15 2017 or higher
#     if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.10)
#         message(FATAL_ERROR "MSVC 19.10 or greater is required to compile (Latest Visual Studio 15 2017 should suffice). Please check the README.md for detailed compilation instructions.")
#     endif ()
# else ()
#     message(WARNING "You are using an unsupported compiler. The compilation is very likely to fail. God speed.")
# endif ()

find_package(Threads)

set(VERSION_MAJOR "2")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")
set(VERSION_IS_DIRTY "")
string(TIMESTAMP timestamp "%y%m%d.%H%M%S" UTC)
set(VERSION_BUILD_TIME "${timestamp}")

## This section describes our general CMake setup options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_SKIP_INSTALL_RULES OFF FORCE)
set(CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY ON FORCE)
set(CMAKE_SUPPRESS_REGENERATION ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

## This section is for settings found in the slow-hash routine(s) that may benefit some systems (mostly ARM)
set(FORCE_USE_HEAP ON CACHE BOOL "Force the use of heap memory allocation")
set(NO_AES OFF CACHE BOOL "Turn off Hardware AES instructions?")
set(NO_OPTIMIZED_MULTIPLY_ON_ARM OFF CACHE BOOL "Turn off Optimized Multiplication on ARM?")
set(STATIC ON CACHE BOOL FORCE "Link libraries statically")
set(PORTABLE ON CACHE STRING "Defaults to ON")
set(BUILD_ARCH "")

function(append_if condition value)
  if (${condition})
    foreach(variable ${ARGN})
      set(${variable} "${${variable}} ${value}" PARENT_SCOPE)
    endforeach(variable)
  endif()
endfunction()

# Check whether we're on a 32-bit or 64-bit system
if(CMAKE_SIZEOF_VOID_P EQUAL "8")
  set(DEFAULT_BUILD_64 ON)
else()
  set(DEFAULT_BUILD_64 OFF)
endif()
option(BUILD_64 "Build for 64-bit? 'OFF' builds for 32-bit." ${DEFAULT_BUILD_64})

if(BUILD_64)
  set(ARCH_WIDTH "64")
else()
  set(ARCH_WIDTH "32")
endif()

if (FORCE_USE_HEAP)
    add_definitions(-DFORCE_USE_HEAP)
endif ()

if (NO_AES)
    add_definitions(-DNO_AES)
endif ()

if (NO_OPTIMIZED_MULTIPLY_ON_ARM)
    add_definitions(-DNO_OPTIMIZED_MULTIPLY_ON_ARM)
endif ()

if (DEFINED ENV{BUILD_ARCH})
  set(BUILD_ARCH $ENV{BUILD_ARCH})
   # message(STATUS "Found BUILD_ARCH: ${BUILD_ARCH}")
else()
  set(BUILD_ARCH "Not Specified")
endif ()

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/version")
include_directories(include src external "${CMAKE_BINARY_DIR}/version")

if(APPLE)
  include_directories(SYSTEM /usr/include/malloc)
  enable_language(ASM)
endif()

if(MSVC)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Windows)
elseif(APPLE)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/OSX)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Posix)
else()
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Linux)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Posix)
endif()

set(STATIC ${MSVC} CACHE BOOL "Link libraries statically")

if(MSVC)
  add_definitions("/bigobj /MP /W3 /GS- /D_CRT_SECURE_NO_WARNINGS /wd4996 /wd4345 /D_WIN32_WINNT=0x0600 /DWIN32_LEAN_AND_MEAN /DGTEST_HAS_TR1_TUPLE=0 /D_VARIADIC_MAX=8 /D__SSE4_1__")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10485760")
  if(STATIC)
    foreach(VAR CMAKE_C_FLAGS_DEBUG CMAKE_CXX_FLAGS_DEBUG CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE)
      string(REPLACE "/MD" "/MT" ${VAR} "${${VAR}}")
    endforeach()
  endif()
  include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/msc)
else()
  if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    # This option has no effect in glibc version less than 2.20. 
    # Since glibc 2.20 _BSD_SOURCE is deprecated, this macro is recomended instead
    add_definitions("-D_DEFAULT_SOURCE -D_GNU_SOURCE")
  endif()

  ## This is here to support building for multiple architecture types... but we all know how well that usually goes...
  if ("${ARCH}" STREQUAL "default")
      set(ARCH_FLAG "")
  else ()
      set(ARCH_FLAG "-march=${ARCH}")
  endif ()

  # set(ARCH native CACHE STRING "CPU to build for: -march value or default")

  set(WARNINGS "-Wall -Wextra -Wpointer-arith -Wundef -Wvla -Wwrite-strings -Wno-error=extra -Wno-error=unused-function -Wno-error=deprecated-declarations -Wno-error=sign-compare -Wno-error=strict-aliasing -Wno-error=type-limits -Wno-unused-parameter -Wno-error=unused-variable -Wno-error=undef -Wno-error=uninitialized -Wno-error=unused-result")
  if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(WARNINGS "${WARNINGS} -Wno-error=mismatched-tags -Wno-unused-lambda-capture -Wno-error=null-conversion -Wno-overloaded-shift-op-parentheses -Wno-error=shift-count-overflow -Wno-error=tautological-constant-out-of-range-compare -Wno-error=unused-private-field -Wno-error=unneeded-internal-declaration -Wno-error=unused-function -Wno-error=missing-braces")
  else ()
    if (NOT APPLE)
      set(WARNINGS "${WARNINGS} -Wlogical-op -Wno-error=maybe-uninitialized -Wno-error=clobbered -Wno-error=unused-but-set-variable")
    endif()
  endif ()
  
  if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "aarch64" OR "${BUILD_ARCH}" STREQUAL "aarch64")
    set(MAES_FLAG "")
  elseif (${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64" AND NOT "${BUILD_ARCH}" STREQUAL "aarch64")
    set(MAES_FLAG "-maes")
  else ()
    set(MAES_FLAG "")
  endif ()

  set(C_WARNINGS "-Waggregate-return -Wnested-externs -Wold-style-definition -Wstrict-prototypes")
  set(CXX_WARNINGS "-Wno-reorder -Wno-missing-field-initializers")

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 ${STATICASSERTC_FLAG} ${WARNINGS} ${C_WARNINGS} ${ARCH_FLAG} ${MAES_FLAG}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ${STATICASSERTCPP_FLAG} ${WARNINGS} ${CXX_WARNINGS} ${ARCH_FLAG} ${MAES_FLAG}")

  if (APPLE)
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdinc++ -I/usr/local/opt/llvm/include/c++/v1 -nodefaultlibs -lc++ -lc++abi -lm -lc -lgcc -lgcc_eh")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCRYPTOPP_CLANG_INTEGRATED_ASSEMBLER=1")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -I/usr/local/opt/llvm/include/c++/v1")
    endif ()
  endif()

  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  endif ()

  ## Setting up DEBUG flags
  if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
      set(DEBUG_FLAGS "-g3 -Og -gdwarf-4 -fvar-tracking -fvar-tracking-assignments -fno-inline -fno-omit-frame-pointer")
  else ()
      set(DEBUG_FLAGS "-g3 -O0 -fno-omit-frame-pointer")
  endif ()

  ## Setting up RELEASE flags
  set(RELEASE_FLAGS "-Ofast -DNDEBUG -Wno-unused-variable")

  if (NOT APPLE)
    # There is a clang bug that does not allow to compile code that uses AES-NI intrinsics if -flto is enabled
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU" AND CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_BUILD_TYPE STREQUAL "Release")
      # On linux, to build in lto mode, check that ld.gold linker is used: 'update-alternatives --install /usr/bin/ld ld /usr/bin/ld.gold HIGHEST_PRIORITY'
      set(CMAKE_AR gcc-ar)
      set(CMAKE_RANLIB gcc-ranlib)
    endif ()
  endif ()

  ## Set up the normal CMake flags as we've built them
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${DEBUG_FLAGS}")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS}")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${RELEASE_FLAGS}")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${RELEASE_FLAGS}")

  if (NOT APPLE)
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
  endif ()

  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    # Unify visibility to meet llvm's default.
    include(CheckCXXCompilerFlag)

    check_cxx_compiler_flag("-fvisibility-inlines-hidden" SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG)
    append_if(SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG "-fvisibility-inlines-hidden" CMAKE_CXX_FLAGS)

    # Disable warnings that produce more headaches than use.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")
  endif()
endif()

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.55 REQUIRED COMPONENTS system filesystem thread date_time chrono regex serialization program_options)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

if(MINGW)
  set(Boost_LIBRARIES "${Boost_LIBRARIES};ws2_32;mswsock;iphlpapi")
elseif(APPLE OR OPENBSD OR ANDROID)
  set(Boost_LIBRARIES "${Boost_LIBRARIES}")
elseif(NOT MSVC)
  set(Boost_LIBRARIES "${Boost_LIBRARIES};rt")
endif()

include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
if(MINGW)
  set(EXTRA_LIBRARIES mswsock;ws2_32;iphlpapi)
elseif(APPLE OR OPENBSD OR ANDROID)
  set(EXTRA_LIBRARIES "")
elseif(FREEBSD)
  set(EXTRA_LIBRARIES execinfo)
elseif(DRAGONFLY)
  find_library(COMPAT compat)
  set(EXTRA_LIBRARIES execinfo ${COMPAT})
elseif(NOT MSVC)
  find_library(RT rt)
  set(EXTRA_LIBRARIES ${RT})
endif()

list(APPEND EXTRA_LIBRARIES ${CMAKE_DL_LIBS})

if(ANDROID AND CMAKE_C_COMPILER_ID STREQUAL "Clang")
  set(ATOMIC ${BOOST_LIBRARYDIR}/libboost_atomic.a)
  set(THREAD ${BOOST_LIBRARYDIR}/libboost_thread.a)
  find_library(THREAD thread)
  list(APPEND EXTRA_LIBRARIES ${THREAD})
  if(ARCH_WIDTH EQUAL "32")
    find_library(ATOMIC atomic)
    list(APPEND EXTRA_LIBRARIES ${ATOMIC})
  endif()
endif()

set(COMMIT_ID_IN_VERSION ON CACHE BOOL "Include commit ID in version")

if (NOT COMMIT_ID_IN_VERSION)
  set(VERSION "${VERSION}-unknown")
  set(COMMIT_ID "unknown")
  # message(STATUS "Version : ${VERSION}")
  # message(STATUS "Revision : ${COMMIT_ID}")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/Config/version.h.in" "${CMAKE_CURRENT_BINARY_DIR}/version/version.h")
  add_custom_target(version ALL)
elseif(DEFINED COMMIT_ID_IN_VERSION)
  find_package(Git QUIET)
  if(Git_FOUND OR GIT_FOUND)
    execute_process(
        COMMAND git rev-parse --abbrev-ref HEAD  # Get the current branch
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

    execute_process(
        COMMAND git log -1 --format=%h # Get latest commit hash
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE COMMIT_ID
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

    execute_process(
        COMMAND git describe --tags --dirty=-Dirty # Get latest commit tags
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE TAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
    string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${TAGS}")
    string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${TAGS}")
    string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH "${TAGS}")
    string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1" VERSION_SHA1 "${TAGS}")
    if(${TAGS} MATCHES "Dirty$")
      set(VERSION_DIRTY "Dirty")
      set(CMAKE_BUILD_TYPE "Debug")
    endif()
    set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}.${COMMIT_ID} ${VERSION_DIRTY}")

  else()
      set(GIT_BRANCH "unknown")
      set(COMMIT_ID "unknown")
  endif()
  set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
  set(VERSION_BUILD_TYPE "${CMAKE_BUILD_TYPE}")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/Config/version.h.in" "${CMAKE_CURRENT_BINARY_DIR}/version/version.h")
  add_custom_target(version ALL)
endif()

add_subdirectory(external)
add_subdirectory(src)
 

message(STATUS "------------------------- ADON BUILD DETAILS ------------------------")
message(STATUS "Version         : ${VERSION_SHORT}")
message(STATUS "Build           : ${VERSION_BUILD_TYPE}")
message(STATUS "Arch            : ${ARCH}")
message(STATUS "Addressing Mode : ${ARCH_WIDTH}")
message(STATUS "BUILD_ARCH      : ${BUILD_ARCH}")
message(STATUS "Compiler        : ${CMAKE_C_COMPILER_ID} version ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Branch          : ${GIT_BRANCH}")
message(STATUS "Version         : ${VERSION} [${VERSION_BUILD_TYPE}.${COMMIT_ID} ${VERSION_DIRTY} ${VERSION_BUILD_TIME}]")
message(STATUS "Boost           : ${Boost_LIB_VERSION}")
message(STATUS "Git             : ${GIT_EXECUTABLE}")
message(STATUS "Libs Static     : ${STATIC}")
message(STATUS "Portable        : ${PORTABLE}")
message(STATUS "FORCE_USE_HEAP  : ${FORCE_USE_HEAP}")
message(STATUS "HW AES          : ${NO_AES}")
message(STATUS "Buid Time       : ${timestamp}")
message(STATUS "---------------------------------------------------------------------")
