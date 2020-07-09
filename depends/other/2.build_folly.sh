#!/usr/bin/env bash

CURRENT_PATH=`pwd`
cd  ${CURRENT_PATH}'folly-master/' \
&& mkdir -p build_ \
&& cd build_/  \
&& cmake -DCMAKE_INCLUDE_PATH=/usr/local/include  \
         -DCMAKE_LIBRARY_PATH=/usr/local/lib:/usr/lib/x86_64-linux-gnu/  \
         -DBoost_USE_STATIC_LIBS=ON  .. \
&& make -j8 \
&& sudo make install \
&& rm -rf ../build_/
