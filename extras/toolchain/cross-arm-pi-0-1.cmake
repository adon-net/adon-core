message(STATUS "Activating GCC 8.3 Cross-Compiler: armv6")

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set (TOOLCHAIN_PREFIX arm-linux-gnueabihf)

set(CMAKE_C_COMPILER   "${TOOLCHAIN_PREFIX}-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}-g++")

set(ARCH armv6 CACHE STRING "CPU to build for: armv6" FORCE)

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -march=armv6 -mfloat-abi=hard -mfpu=vfp -Wno-unused-variable -Wno-unused-function -Wno-psabi")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv6 -mfloat-abi=hard -mfpu=vfp -Wno-unused-variable -Wno-unused-function -Wno-psabi")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
