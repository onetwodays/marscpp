#!/usr/bin/env bash
#git clone https://github.com/mfontanini/cppkafka.git
cd  ../pkg/cppkafka  \
     && mkdir -p build \
     && cd build/ \
     &&  cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DCPPKAFKA_RDKAFKA_STATIC_LIB=ON -DCPPKAFKA_BUILD_SHARED=OFF .. \
     &&  make -j8 \
     &&  sudo make install \
     &&  rm -rf ../build/