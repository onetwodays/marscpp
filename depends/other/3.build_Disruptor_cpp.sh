#!/usr/bin/env bash
CURRENT_PATH=`pwd`
cd  ${CURRENT_PATH}'Disruptor-cpp/' \
&& mkdir -p build \
&& cd build/  \
&& cmake -DCMAKE_BUILD_TYPE=release \
         -DDISRUPTOR_BUILD_TESTS=false \
         -DBoost_USE_STATIC_LIBS=ON  .. \
&& make -j8 \
&& sudo make install \
&& rm -rf ../build/

