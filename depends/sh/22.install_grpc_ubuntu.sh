#!/usr/bin/env bash
#https://github.com/grpc/grpc/blob/master/BUILDING.md
#ubuntu   apt-get install build-essential autoconf libtool pkg-config
#git config --global https.proxy https://192.168.36.1:3128
git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
cd grpc
git submodule update --init
mkdir -p cmake/build
cd cmake/build
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DgRPC_BUILD_TESTS=OFF \
  -DgRPC_SSL_PROVIDER=package \
  -DgRPC_ZLIB_PROVIDER=package \
  ../..
make -j8
sudo make install
cd ../../..
mv  grpc ~/pkg/


# To install gRPC on your system, follow the instructions to build from source here.
# This also installs the protocol buffer compiler protoc (if you don't have it already),
# and the C++ gRPC plugin for protoc.

/*
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DgRPC_BUILD_TESTS=OFF \
  -DgRPC_CARES_PROVIDER=package \
  -DgRPC_ABSL_PROVIDER=package \
  -DgRPC_PROTOBUF_PROVIDER=package \
  -DgRPC_SSL_PROVIDER=package \
  -DgRPC_ZLIB_PROVIDER=package \
  ../..
*/