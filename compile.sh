if [ ! -d "build" ]; then
  mkdir build
  cd build
  cmake ..
  else
  cd build
fi

if [ $? -ne 0 ]; then
  exit
fi
make -j4
if [ $? -ne 0 ]; then
  exit
fi
./../output/dt_test
