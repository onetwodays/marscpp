#!/usr/bin/env bash
CURRENT_PATH=`pwd`
cd  ${CURRENT_PATH}'../pkg/fmt-6.0.0/'  \
    && mkdir -p build  \
    && cd build  \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DFMT_TEST=FALSE ..   \
    && make -j4   \
    && sudo make install \
    && rm -rf ../build/
