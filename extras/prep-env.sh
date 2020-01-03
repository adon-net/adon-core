#!/bin/bash

export BASEDIR=`pwd`
export TOOLCHAIN_DIR=$HOME/.buildenv/toolchain
export BOOST_VER=1.65.1
export BOOST_ROOT=$HOME/.buildenv/boost_${BOOST_VER//[.]/_}
export CUSTOM_TOOLCHAIN_FILE=""

CROSS_GCC=cross-gcc-8.3.0
CROSS_PI=cross-pi-gcc-8.3.0

BOOST_SRC=boost_${BOOST_VER//[.]/_}
BOOST_SRC_FILE=$BOOST_SRC.tar.gz

SOURCE_FORGE_PROJECT="https://sourceforge.net/projects"
BASE_PI_32_URL="raspberry-pi-cross-compilers/files/Raspberry%20Pi%20GCC%20Cross-Compiler%20Toolchains/GCC%208.3.0"
BASE_PI_64_URL="raspberry-pi-cross-compilers/files/Bonus%20Raspberry%20Pi%20GCC%2064-Bit%20Toolchains/Raspberry%20Pi%20GCC%2064-Bit%20Cross-Compiler%20Toolchains/GCC%208.3.0"
BASE_BOOST_URL="boost/files/boost/$BOOST_VER"

mkdir -p $TOOLCHAIN_DIR && mkdir -p $BOOST_ROOT

__print_env(){
  echo "..... ALL DONE .....  "
  echo "Toolchain path       # " $TOOLCHAIN_DIR
  echo "Boost root dir       # " $BOOST_ROOT
}

__download_boost(){
  # rm -rf /tmp/boost*
  if [ ! -d "/tmp/$BOOST_SRC" ] 
  then
    if [ ! -f "/tmp/$BOOST_SRC_FILE" ]
    then
      wget $SOURCE_FORGE_PROJECT/$BASE_BOOST_URL/$BOOST_SRC_FILE -O /tmp/$BOOST_SRC.tar.gz -q --show-progress
    fi
  fi
  cd /tmp
  tar xfv /tmp/$BOOST_SRC_FILE -C /tmp >/dev/null
  cd /tmp/$BOOST_SRC
}

_setup_toolchain_armv6_x86(){
  _TOOLCHAIN_FOLDER=$CROSS_GCC-pi_0-1
  _TOOLCHAIN_FILE=$_TOOLCHAIN_FOLDER.tar.gz
  echo "...Chekcing toolchain: " $CROSS_PI

  if [ ! -f "$TOOLCHAIN_DIR/$CROSS_PI-0/bin/arm-linux-gnueabihf-g++" ]
  then
    if [ ! -f "/tmp/$_TOOLCHAIN_FILE" ]
    then
      echo "....Downloading      : " $_TOOLCHAIN_FILE
      wget $SOURCE_FORGE_PROJECT/$BASE_PI_32_URL/Raspberry%20Pi%201%2C%20Zero/$_TOOLCHAIN_FILE -O /tmp/$_TOOLCHAIN_FILE -q --show-progress
    fi
    cd /tmp
    echo "....Extracting       : " $_TOOLCHAIN_FILE
    tar xfv /tmp/$_TOOLCHAIN_FILE -C $TOOLCHAIN_DIR 
  fi
  echo "....Setting up       : " $CROSS_GCC-pi_0-1
  export TOOLCHAIN_DIR=$TOOLCHAIN_DIR/$CROSS_PI-0
  export PATH=$PATH:$TOOLCHAIN_DIR/bin
  cd $BASEDIR
}

_setup_toolchain_armv7-a_x86(){
  _TOOLCHAIN_FOLDER=$CROSS_GCC-pi_2-3
  _TOOLCHAIN_FILE=$_TOOLCHAIN_FOLDER.tar.gz
  echo "...Chekcing toolchain: " $CROSS_PI

  if [ ! -f "$TOOLCHAIN_DIR/$CROSS_PI-1/bin/arm-linux-gnueabihf-g++" ]
  then
    if [ ! -f "/tmp/$_TOOLCHAIN_FILE" ]
    then
      echo "....Downloading      : " $_TOOLCHAIN_FILE
      wget $SOURCE_FORGE_PROJECT/$BASE_PI_32_URL/Raspberry%20Pi%202%2C%203/$_TOOLCHAIN_FILE -O /tmp/$_TOOLCHAIN_FILE -q --show-progress
    fi
    cd /tmp
    echo "....Extracting       : " $_TOOLCHAIN_FILE
    tar xfv /tmp/$_TOOLCHAIN_FILE -C $TOOLCHAIN_DIR  > /dev/null
  fi
  echo "....Setting up       : " $CROSS_GCC-pi_2-3
  export TOOLCHAIN_DIR=$TOOLCHAIN_DIR/$CROSS_PI-1
  export PATH=$PATH:$TOOLCHAIN_DIR/bin
  cd $BASEDIR
}

_setup_toolchain_armv8-a_x86(){
  _TOOLCHAIN_FOLDER=$CROSS_GCC-pi_3+
  _TOOLCHAIN_FILE=$_TOOLCHAIN_FOLDER.tar.gz
  if [ ! -f "$TOOLCHAIN_DIR/$CROSS_PI-2/bin/arm-linux-gnueabihf-g++" ]
  then
    if [ ! -f "/tmp/$_TOOLCHAIN_FILE" ]
    then
      echo "....Downloading      : " $_TOOLCHAIN_FILE
      wget $SOURCE_FORGE_PROJECT/$BASE_PI_32_URL/Raspberry%20Pi%203A%2B%2C%203B%2B%2C%204/$_TOOLCHAIN_FILE -O /tmp/$_TOOLCHAIN_FILE -q --show-progress
    fi
    cd /tmp
    echo "....Extracting       : " $_TOOLCHAIN_FILE
    tar xfv /tmp/$_TOOLCHAIN_FILE -C $TOOLCHAIN_DIR  > /dev/null
  fi
  echo "....Setting up       : " $CROSS_GCC-pi_3+
  export TOOLCHAIN_DIR=$TOOLCHAIN_DIR/$CROSS_PI-2
  export PATH=$PATH:$TOOLCHAIN_DIR/bin
  cd $BASEDIR
}

_setup_toolchain_armv8-a_x64(){
  _TOOLCHAIN_FOLDER=$CROSS_GCC-pi_64
  _TOOLCHAIN_FILE=$_TOOLCHAIN_FOLDER.tar.gz
    echo "...Chekcing toolchain: " $CROSS_PI

  if [ ! -f "$TOOLCHAIN_DIR/$CROSS_PI-64/bin/aarch64-linux-gnu-g++" ]
  then
    if [ ! -f "/tmp/$_TOOLCHAIN_FILE" ]
    then
          echo "....Downloading      : " $_TOOLCHAIN_FILE
      wget $SOURCE_FORGE_PROJECT/$BASE_PI_64_URL/$_TOOLCHAIN_FILE -O /tmp/$_TOOLCHAIN_FILE -q --show-progress
    fi
    cd /tmp
    echo "....Extracting       : " $_TOOLCHAIN_FILE

    tar xfv /tmp/$_TOOLCHAIN_FILE -C $TOOLCHAIN_DIR  > /dev/null
  fi
    echo "....Setting up       : " $CROSS_GCC-pi_64

  export TOOLCHAIN_DIR=$TOOLCHAIN_DIR/$CROSS_PI-64
  export PATH=$PATH:$TOOLCHAIN_DIR/bin

  cd $BASEDIR
}

_build_boost_x86_64_x86(){
  export BOOST_ROOT=$BOOST_ROOT/x86
  echo "...Chekcing Boost    : " $BOOST_SRC

  if [ ! -f "$BOOST_ROOT/lib/libboost_atomic-mt.a" ]
  then
    echo "....Downloading      : " $BOOST_SRC
    __download_boost
 
    echo "....Bootstraping     : " $BOOST_SRC
    ./bootstrap.sh > /dev/null

    echo "....Compiling        : " $BOOST_SRC
    ./b2 -j8 \
      cxxflags="-m32" linkflags="-m32" \
      link=static address-model=32 architecture=x86 threading=multi \
      --reconfigure --prefix=$BOOST_ROOT install --build-type=complete --layout=tagged \
      --with-atomic --with-chrono --with-date_time --with-filesystem --with-program_options \
      --with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine > /dev/null
  else
    echo "...Boost found .." $BOOST_SRC
  fi
  cd $BASEDIR
}

_build_boost_armv6_x86(){
  export BOOST_ROOT=$BOOST_ROOT/armv6/x86
  echo "...Chekcing Boost    : " $BOOST_SRC

  if [ ! -f "$BOOST_ROOT/lib/libboost_atomic.a" ]
  then
    echo "....Downloading      : " $BOOST_SRC
    __download_boost

    echo "....Bootstraping     : " $BOOST_SRC
    echo "using gcc : arm : ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++ ;" > user-config-arm-pi-0-1-32.jam
    ./bootstrap.sh

    echo "....Compiling        : " $BOOST_SRC 
    ./b2 -j8 \
      toolset=gcc-arm cxxflags="-std=c++11" linkflags="-std=c++11" \
      --reconfigure --prefix=$BOOST_ROOT install \
      --with-atomic --with-chrono --with-date_time --with-filesystem --with-program_options \
      --with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine \
      --user-config=user-config-arm-pi-0-1-32.jam > /dev/null
  else
    echo "....Boost found      : " $BOOST_SRC
  fi
  cd $BASEDIR
}

_build_boost_armv7-a_x86(){
  cd /tmp/boost_${BOOST_VER//[.]/_}
  export BOOST_ROOT=$BOOST_ROOT/armv7-a/x86
  echo "...Chekcing Boost    : " $BOOST_SRC

  if [ ! -f "$BOOST_ROOT/lib/libboost_atomic.a" ]
  then
    echo "....Downloading      : " $BOOST_SRC
    __download_boost

    echo "....Bootstraping     : " $BOOST_SRC
    echo "using gcc : arm : ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++ ;" > user-config-arm-pi-2-3-32.jam
    ./bootstrap.sh > /dev/null

    echo "....Compiling        : " $BOOST_SRC 
    ./b2 -j8 \
      toolset=gcc-arm cxxflags="-std=c++11" linkflags="-std=c++11" \
      --reconfigure --prefix=$BOOST_ROOT install \
      --with-atomic --with-chrono --with-date_time --with-filesystem --with-program_options \
      --with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine \
      --user-config=user-config-arm-pi-2-3-32.jam > /dev/null
  else
    echo "....Boost found      : " $BOOST_SRC
  fi
  cd $BASEDIR
}

_build_boost_armv8-a_x86(){
  cd /tmp/boost_${BOOST_VER//[.]/_}
  export BOOST_ROOT=$BOOST_ROOT/armv8-a/x86
  if [ ! -f "$BOOST_ROOT/lib/libboost_atomic.a" ]
  then
    echo "....Downloading      : " $BOOST_SRC
    __download_boost

    echo "....Bootstraping     : " $BOOST_SRC
    echo "using gcc : aarch64 : ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++ ;" > user-config-arm-pi-3+-32.jam
    ./bootstrap.sh > /dev/null

    echo "....Compiling        : " $BOOST_SRC 
    ./b2 -j8 \
      toolset=gcc-aarch64 cxxflags="-std=c++11" linkflags="-std=c++11" \
      --reconfigure --prefix=$BOOST_ROOT install \
      --with-atomic --with-chrono --with-date_time --with-filesystem --with-program_options \
      --with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine \
      --user-config=user-config-arm-pi-3+-32.jam > /dev/null
  else
    echo "....Boost found      : " $BOOST_SRC
  fi
  cd $BASEDIR
}

_build_boost_armv8-a_x64(){
  cd /tmp/boost_${BOOST_VER//[.]/_}
  export BOOST_ROOT=$BOOST_ROOT/armv8-a/x64
  if [ ! -f "$BOOST_ROOT/lib/libboost_atomic.a" ]
  then
    echo "....Downloading      : " $BOOST_SRC
    __download_boost

    echo "....Bootstraping     : " $BOOST_SRC
    echo "using gcc : aarch64 : ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-g++ ;" > user-config-arm-pi-3+-64.jam
    ./bootstrap.sh > /dev/null

    echo "....Compiling        : " $BOOST_SRC 
    ./b2 -j8 \
      toolset=gcc-aarch64 \
      cxxflags="-std=c++11" linkflags="-std=c++11" \
      --reconfigure --prefix=$BOOST_ROOT install \
      --with-atomic --with-chrono --with-date_time --with-filesystem --with-program_options \
      --with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine \
      --user-config=user-config-arm-pi-3+-64.jam > /dev/null
  else
    echo "....Boost found      : " $BOOST_SRC
  fi
  cd $BASEDIR
}

setup_env_x86_64_x86(){
  echo "Setting up boost for :  x86_64 32Bit"
  _build_boost_x86_64_x86

  export CUSTOM_TOOLCHAIN_FILE=$BASEDIR/extras/toolchain/cross-linux-x86.cmake

  __print_env
}

setup_env_armv6_x86(){
  echo "Setting up toolchain :  armv6 x86"
  _setup_toolchain_armv6_x86
  echo "Setting up boost for :  armv6 x86"
  _build_boost_armv6_x86  

  export CUSTOM_TOOLCHAIN_FILE=$BASEDIR/extras/toolchain/cross-arm-pi-0-1.cmake

  __print_env
}

setup_env_armv7-a_x86(){
  echo "Setting up toolchain :  armv7-a x86"
  _setup_toolchain_armv7-a_x86 
  echo "Setting up boost for :  armv7-a x86"
  _build_boost_armv7-a_x86 

  export CUSTOM_TOOLCHAIN_FILE=$BASEDIR/extras/toolchain/cross-arm-pi-2-3.cmake

  __print_env
}

setup_env_armv8-a_x86(){
  echo "Setting up toolchain : armv8-a x86"
  _setup_toolchain_armv8-a_x86 
  echo "Setting up boost for : armv8-a x86"
  _build_boost_armv8-a_x86 

  export CUSTOM_TOOLCHAIN_FILE=$BASEDIR/extras/toolchain/cross-arm-pi-3+-32.cmake

  __print_env
}

setup_env_armv8-a_x64(){
  echo "Setting up toolchain : armv8-a x64"
  _setup_toolchain_armv8-a_x64 
  echo "Setting up boost for : armv8-a x64"
  _build_boost_armv8-a_x64 

  export CUSTOM_TOOLCHAIN_FILE=$BASEDIR/extras/toolchain/cross-arm-pi-3+-64.cmake

  __print_env
}


if [ -z "$_ENV_ARCH" ]
then
  __ARCH=$1
else
  __ARCH=$_ENV_ARCH
fi

case $__ARCH in
  armv6_x86)
    setup_env_armv6_x86
    ;;
  armv7-a_x86)
    setup_env_armv7-a_x86
    ;;
  armv8-a_x86)
    setup_env_armv8-a_x86
    ;;
  armv8-a_x64)
    setup_env_armv8-a_x64
    ;;
  x86_64_x86)
    setup_env_x86_64_x86
    ;;
  *)
    echo "Can't  perpare environment"
    ;;
esac
