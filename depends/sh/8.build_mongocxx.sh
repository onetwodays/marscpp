#!/usr/bin/env bash
CURRENT_PATH=`pwd`

#http://mongoc.org/libmongoc/current/installing.html
# sudo yum install cmake openssl-devel cyrus-sasl-devel 或 sudo apt-get install cmake libssl-dev libsasl2-dev
# sudo /usr/local/share/mongo-c-driver/uninstall.sh 或sudo make uninstall 卸载编译的动态库



cd  ${CURRENT_PATH}'../pkg/' \
&& tar xzf   mongo-cxx-driver-debian-3.4.0-1.tar.gz \
&& cd   ${CURRENT_PATH}'/depends/mongo-cxx-driver-debian-3.4.0-1/build'  \
&&  cmake  -DCMAKE_INCLUDE_PATH=/usr/local/include  \
           -DCMAKE_LIBRARY_PATH=/usr/local/lib \
           -DCMAKE_BUILD_TYPE=Release  -DBUILD_SHARED_LIBS=OFF -DBSONCXX_POLY_USE_BOOST=1 -DCMAKE_INSTALL_PREFIX=/usr/local .. \
&&  make -j8  \
&&  sudo make install \
&&  sudo rm -rf  ${CURRENT_PATH}'../pkg/mongo-cxx-driver-debian-3.4.0-1/' \
