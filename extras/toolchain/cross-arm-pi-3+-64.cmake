message(STATUS "Activating GCC 8.3 Cross-Compiler: aarch64")

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set (TOOLCHAIN_PREFIX aarch64-linux-gnu)

set(CMAKE_C_COMPILER   "${TOOLCHAIN_PREFIX}-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}-g++")

set(ARCH armv8-a CACHE STRING "CPU to build for: armv8-a" FORCE)

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -march=armv8-a -Wno-unused-variable -Wno-unused-function -Wno-psabi")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv8-a -Wno-unused-variable -Wno-unused-function -Wno-psabi")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
