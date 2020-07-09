#!/usr/bin/env bash
#依赖jansson库
cd ../pkg
tar zxvf  avro-c-1.9.1.tar.gz
cd avro-c-1.9.1
mkdir cmake-build
cd cmake-build
cmake ..
make -j8 && sudo make install
cd ../../
mv avro-c-1.9.1 ~/pkg/
