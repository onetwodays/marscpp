#!/usr/bin/env bash
mkdir -p tmp
cd tmp/
git clone https://github.com/gflags/gflags.git
cd gflags
git checkout v2.0
./configure && make && sudo make install
cd ../


wget https://github.com/facebook/zstd/archive/v1.1.3.tar.gz
mv v1.1.3.tar.gz zstd-1.1.3.tar.gz
tar zxvf zstd-1.1.3.tar.gz
cd zstd-1.1.3
make && sudo make install
cd ../

sudo yum install snappy snappy-devel
sudo yum install zlib zlib-devel
sudo yum install bzip2 bzip2-devel
sudo yum install lz4-devel
sudo yum install libasan
