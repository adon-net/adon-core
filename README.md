
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

## **ON LINUX:**

### **UBUNTU**

- `sudo apt update && apt install -y  software-properties-common build-essential wget file cmake git libssl-dev`

#### Install latest CMake

- `cd /tmp`
- `wget https://github.com/Kitware/CMake/releases/download/v3.16.2/cmake-3.16.2.tar.gz > /dev/null`
- `tar xzvf cmake-3.16.2.tar.gz`
- `cd cmake-3.16.2 && ./bootstrap`
- `make -j$(proc)`
- `sudo make install`
  
#### Install gcc-7 & g++-7  

- `sudo add-apt-repository ppa:ubuntu-toolchain-r/test`
- `sudo apt install g++-7 -y`
- `sudo update-alternatives \`
    `--install /usr/bin/gcc gcc /usr/bin/gcc-7 60 \`
    `--slave /usr/bin/g++ g++ /usr/bin/g++-7 \`
    `--slave /usr/bin/gcc-ar gcc-ar /usr/bin/gcc-ar-7 \`
    `--slave /usr/bin/gcc-nm gcc-nm /usr/bin/gcc-nm-7 \`
    `--slave /usr/bin/gcc-ranlib gcc-ranlib /usr/bin/gcc-ranlib-7`

For 64-bit:

- `sudo apt install -y libboost-all-dev`

#### Compile Adon Coin

  - `cd ~`
  - `git clone -b master --single-branch https://github.com/adon-net/adon-core`
  - `cd adon-core`
  - `cmake -S . -Bbuild -DSTATIC=ON`
  - `cmake --build build -j$(nproc)`
  - You can find binaries under build/src folder.

  For 32-bit:

  Install additional software required to compile 32 bit;

  - `apt install -y gcc-7-multilib g++-7-multilib libc6-dev-i386`
    
  You need to compile boost libraries from source code.

  - `cd /tmp`
  - `wget https://sourceforge.net/projects/boost/files/boost/1.65.1/boost_1_65_1.tar.gz`
  - `tar xzvf boost_1_65_1.tar.gz`
  - `cd boost_1_65_1`
  - `export BOOST_ROOT=$HOME/local/boost_1_65_1/x86`
  - `./bootstrap.sh`
  - `./b2 -j8 \`
      `cxxflags="-m32" linkflags="-m32" \`
      `link=static address-model=32 architecture=x86 threading=multi \`
      `--reconfigure --prefix=$BOOST_ROOT install --build-type=complete --layout=tagged \`
      `--with-atomic --with-chrono --with-date_time --with-filesystem --with-program_options \`
      `--with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine > /dev/null`

#### Compile Adon Coin

  - `cd ~`
  - `git clone -b master --single-branch https://github.com/adon-net/adon-core`
  - `cd adon-core`
  - `cmake -S . -Bbuild -DSTATIC=ON -DCMAKE_TOOLCHAIN_FILE=./extras/toolchain/cross-linux-x86.cmake`
  - `cmake --build build -j$(nproc)`
  - You can find binaries under build/src folder.
 

## **RASPBERRY PI**

  #### **CROSS COMPILE FOR PI 0 & 1**

  `This part of the document will be updated soon`

  #### **CROSS COMPILE FOR PI 2 & 3**

  `This part of the document will be updated soon`

  #### **CROSS COMPILE FOR PI 3+**

  `This part of the document will be updated soon`

## **ON WINDOWS:**

#### PREREQUISITES
 
- [Microsoft Visual Studio Build Tools 2017/2019](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16)
- [CMake v3.8+](http://www.cmake.org/)
- [Boost Library v1.65+](http://www.boost.org/)
  - [Boost 64-bit](https://bintray.com/boostorg/release/download_file?file_path=1.69.0%2Fbinaries%2Fboost_1_69_0-msvc-14.1-64.exe)
  - [Boost 32-bit](https://bintray.com/boostorg/release/download_file?file_path=1.69.0%2Fbinaries%2Fboost_1_69_0-msvc-14.1-32.exe)


### WITH VISUAL STUDIO 2019

For 64-bit:

- From the start menu, open 'x64 Native Tools Command Prompt for VS 2019'.
- `git clone -b master --single-branch https://github.com/adon-net/adon-core`
- `cd adon-core`
- `mkdir build`
- `cd build`
- `cmake -G "Visual Studio 16 2019" -A x64 .. -DBOOST_ROOT=C:/local/boost_1_69_0`
- `MSBuild Adon.sln /p:Configuration=Release /m`

For 32-bit:

- From the start menu, open 'x86 Native Tools Command Prompt for VS 2019'.
- `git clone -b master --single-branch https://github.com/adon-net/adon-core`
- `cd adon-core`
- `mkdir build`
- `cd build`
- `cmake -G "Visual Studio 16 2019" -A Win32 .. -DBOOST_ROOT=C:/local/boost_1_69_0`
- `MSBuild Adon.sln /p:Configuration=Release /p:Platform=Win32 /m` 

The binaries will be in the `src/Release` folder when you are complete.

- `cd src`
- `cd Release`
- `adon-daemon.exe --version`

### WITH VISUAL STUDIO 2017

For 64-bit:

- From the start menu, open 'x64 Native Tools Command Prompt for VS 2017'.
- `git clone -b master --single-branch https://github.com/adon-net/adon-core`
- `cd adon-core`
- `mkdir build`
- `cd build`
- `cmake -G "Visual Studio 15 2017 Win64" .. -DBOOST_ROOT=C:/local/boost_1_69_0`
- `MSBuild Adon.sln /p:Configuration=Release /m`

For 32-bit:

- From the start menu, open 'x86 Native Tools Command Prompt for VS 2017'.
- `git clone -b master --single-branch https://github.com/adon-net/adon-core`
- `cd adon-core`
- `mkdir build`
- `cd build`
- `cmake -G "Visual Studio 15 2017" .. -DBOOST_ROOT=C:/local/boost_1_69_0`
- `MSBuild Adon.sln /p:Configuration=Release /p:Platform=Win32 /m` 

The binaries will be in the `src/Release` folder when you are complete.

- `cd src`
- `cd Release`
- `adon-daemon.exe --version`

And then do Build.
Good luck!
