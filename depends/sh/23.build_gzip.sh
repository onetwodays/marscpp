#!/usr/bin/env bash
#grpc 依赖gzip ,可以先不安装 ,库文件叫做z
cd ../pkg
tar -zxvf gzip-1.10.tar.gz
cd gzip-1.10
./configure --prefix=/usr/local  && make -j8 && sudo make install

cd ..
mv gzip-1.10  ~/pkg/