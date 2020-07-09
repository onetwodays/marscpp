#!/usr/bin/env bash
#wget https://codeload.github.com/protocolbuffers/protobuf/tar.gz/v3.11.2
tar zxvf  protobuf-3.11.2.tar.gz
mv protobuf-3.11.2 protobuf

#git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
#git submodule update --init --recursive
./autogen.sh

./configure && make -j8 && sudo make install
cd ..
mv protobuf  ~/pkg/

