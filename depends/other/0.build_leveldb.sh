#!/usr/bin/env bash

CURRENT_PATH=`pwd`
cd  ${CURRENT_PATH}'leveldb-master/' \
&& mkdir -p build \
&& cd build/ \
&& cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_SHARED_LIBS=FALSE -DLEVELDB_BUILD_TESTS=FALSE -DLEVELDB_BUILD_BENCHMARKS=FALSE .. \
&& make -j8  \
&& sudo make install \
&& rm -rf ../build/
# 库文件和头文件放在默认路径下. /usr/local/lib/libleveldb.a  和 /usr/local/include/leveldb/
#&& cp -r -f libleveldb.a ${CURRENT_PATH}'/lib' \
#

#-DCMAKE_BUILD_TYPE=Release
# git clone --recurse-submodules https://github.com/google/leveldb.git