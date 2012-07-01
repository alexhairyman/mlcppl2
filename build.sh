if [ $1 == "debug" ]; then
  mkdir -p build_debug
  (
    if [ ! `echo $PWD | grep -ioE '[^/]+$'` == "build_debug" ]; then
      cd build_debug
    fi
    cmake ../ -G "CodeBlocks - Unix Makefiles"
  )
elif [ $1 == "release" ]; then
  mkdir -p build
  (
    if [ ! `echo $PWD | grep -ioE '[^/]+$'` == "build" ]; then
      cd build
    fi
    cmake ../ -G "CodeBlocks - Unix Makefiles"
  )
fi
