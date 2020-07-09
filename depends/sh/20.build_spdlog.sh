#!/usr/bin/env bash

 CURRENT_PATH=`pwd`
cd  ${CURRENT_PATH}'../pkg/spdlog/' \
&& mkdir -p build \
&& cd build/ \
&& cmake -DCMAKE_INSTALL_PREFIX=/usr/local  .. \
&& make -j8  \
&& sudo make install \
&& rm -rf ../build/

