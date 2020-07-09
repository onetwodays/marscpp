#!/usr/bin/env bash
CURRENT_PATH=`pwd`

#http://mongoc.org/libmongoc/current/installing.html
# sudo yum install cmake openssl-devel cyrus-sasl-devel 或 sudo apt-get install cmake libssl-dev libsasl2-dev
# sudo /usr/local/share/mongo-c-driver/uninstall.sh 或sudo make uninstall 卸载编译的动态库
cd ${CURRENT_PATH}'../pkg' \
&& tar xzf mongo-c-driver-1.15.1.tar.gz  \
&& cd  mongo-c-driver-1.15.1 \
&& mkdir cmake-build \
&& cd   cmake-build  \
&& cmake -LH .. \
&& cmake   -DCMAKE_INCLUDE_PATH=/usr/local/include  \
           -DCMAKE_LIBRARY_PATH=/usr/local/lib \
           -DCMAKE_INSTALL_PREFIX=/usr/local -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF  -DENABLE_STATIC=ON -DENABLE_EXAMPLES=OFF -DENABLE_TESTS=OFF ..  \
&& make -j4 \
&& sudo make install \
&&  sudo rm -rf  ${CURRENT_PATH}'../pkg/mongo-c-driver-1.15.1/'
# http://mongocxx.org/mongocxx-v3/installation/




