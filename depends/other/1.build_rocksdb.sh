#!/usr/bin/env bash


CURRENT_PATH=`pwd`
cd  ${CURRENT_PATH}'rocksdb-master/' \
&& mkdir -p build \
&& cd build/ \
&& cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DWITH_TESTS=FALSE -DWITH_TOOLS=FALSE .. \
&& make -j8  \
&& sudo make install \
&& rm -rf ../build/
#&& cp -r -f librocksdb.a ${CURRENT_PATH}'/lib' \
