#!/bin/bash

#builds with the various build files

ARG1=$1
ARG2=$2

if [ `pwd | grep -oE '[^/]+$'` == 'support' ]; then
  MYPREFIX=..
else
  MYPREFIX=.
fi

echo $MYPREFIX

function initb #initialize build
{
  if [ `pwd | grep -Eo '[^/]+$'` == 'support' ]; then
    mkdir -p $MYPREFIX/bdir/{jbuild,nbuild,build,build_debug}
  else
    mkdir -p $MYPREFIX/bdir/{jbuild,nbuild,build,build_debug}
  fi
}

function mvtt #move to top
{
  if [ `pwd | grep -Eo '[^/]+$'` == 'support' ]; then
    cp ./$1 ../$1
  else
    echo cp ./support/$1 ./$1
  fi
}

function cleanbdir
{
  if [ `pwd | grep -Eo '[^/]+$'` == 'support' ]; then
    rm -rf ../bdir/ ../build.ninja ../Jamfile #{jbuild,nbuild,build,build_debug}
  else
    rm -rf bdir/ build.ninja Jamfile #{jbuild,nbuild,build,build_debug}
  fi
}

#the ninja build
function ninjabuild
{
  initb
  mvtt build.ninja
  cd $MYPREFIX; ninja statarcy
}

#the jam build
function jambuild
{
  initb
  mvtt Jamfile
  cd $MYPREFIX; jam lib
}

#the cmake build
function cmakebuild
{
  initb
  if [ ! `pwd | grep -oE '[^/]+$'` == 'support' ]; then
    MYPREFIX = ..
  else
    MYPREFIX = .
  fi
  
  if [ $1 == 'release' ]; then
    cd $MYPREFIX/bdir/build/
    cmake ../../ -G "CodeBlocks - Unix Makefiles"
    make
  elif [ $1 == 'debug' ]; then
    cd $MYPREFIX/bdir/build_debug/
    cmake ../../ -G "CodeBlocks - Unix Makefiles"
    make
  fi
    
}

if [ $ARG1 == 'cmake' ] && [ ! $ARG2 == '' ]; then
  if [ $ARG2 == 'release' ]; then
    cmakebuild release
  elif [ $2 == 'debug' ]; then
    cmakebuild debug
  else
    cmakebuild release
  fi
elif [ $ARG1 == 'ninja' ]; then
  ninjabuild
elif [ $ARG1 == 'jam' ]; then
  jambuild
elif [ $ARG1 == 'clean' ]; then
  cleanbdir
else
  echo -e \
  "$ARG1 Not recognized, possible targets are 
  cmake [build,debug] \n  jam\n  ninja\n  clean"
fi
