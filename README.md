
#### BRANCH  : MASTER
[![nix 64-bit](https://img.shields.io/travis/adon-net/adon-core/master.svg?label=nix.x64&logo=travis&style=for-the-badge)](https://travis-ci.org/adon-net/adon-core) 
[![win 64-bit](https://img.shields.io/appveyor/ci/adon-net/adon-core/master?label=win.x64&logo=appveyor&style=for-the-badge)](https://ci.appveyor.com/project/adon-net/adon-core/branch/master)

![GitHub last commit (branch)](https://img.shields.io/github/last-commit/adon-net/adon-core/master?logo=git&style=for-the-badge)
![GitHub commits since latest release (branch)](https://img.shields.io/github/commits-since/adon-net/adon-core/v1.1.0/master?logo=git&style=for-the-badge)

#### BRANCH  : DEVELOP 
[![nix 64-bit](https://img.shields.io/travis/adon-net/adon-core/develop?label=nix.x64&logo=travis&style=for-the-badge)](https://travis-ci.org/adon-net/adon-core) 
[![win 64-bit](https://img.shields.io/appveyor/ci/adon-net/adon-core/develop?label=win.x64&logo=appveyor&style=for-the-badge)](https://ci.appveyor.com/project/adon-net/adon-core/branch/develop)  

![GitHub last commit (branch)](https://img.shields.io/github/last-commit/adon-net/adon-core/develop?logo=git&style=for-the-badge)
![GitHub commits since latest release (branch)](https://img.shields.io/github/commits-since/adon-net/adon-core/v1.1.0/develop?logo=git&style=for-the-badge)

#### RELEASE
![GitHub Release Date](https://img.shields.io/github/release-date/adon-net/adon-core?logo=git&style=for-the-badge)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/adon-net/adon-core?logo=git&style=for-the-badge)
![GitHub All Releases](https://img.shields.io/github/downloads/adon-net/adon-core/total?logo=git&style=for-the-badge)

![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/adon-net/adon-core?logo=git&style=for-the-badge) 
![GitHub repo size](https://img.shields.io/github/repo-size/adon-net/adon-core?logo=git&style=for-the-badge) 

![GitHub language count](https://img.shields.io/github/languages/count/adon-net/adon-core?logo=git&style=for-the-badge)

## Building Adon Coin

### On *nix:

Dependencies: GCC 5.5.0 or later, CMake 3+ or later, and Boost 1.55 or later.

You may download them from:

- http://gcc.gnu.org/
- http://www.cmake.org/
- http://www.boost.org/

Alternatively, it may be possible to install them using a package manager.

To build, change to a directory where this file is located, and run `make`. The resulting executables can be found in `build/release/src`.

#### Advanced options:

Parallel build: run `make -j<number of threads>` instead of `make`.

Debug build: run `make build-debug`.

Test suite: run `make test-release` to run tests in addition to building. Running `make test-debug` will do the same to the debug version.

Building with Clang: it may be possible to use Clang instead of GCC, but this may not work everywhere. To build, run `export CC=clang CXX=clang++` before running `make`.

### On Windows:
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55 or later. You may download them from:

- http://www.microsoft.com/
- http://www.cmake.org/
- http://www.boost.org/

To build, change to a directory where this file is located, and run this commands:
```
mkdir build
cd build
cmake -G "Visual Studio 12 Win64" ..
```


And then do Build.

Good luck!
