#!/usr/bin/env bash
#安装cmake v3.15.3 因为clion IDE支持的最大版本是这个
git clone -b v3.15.3 https://github.com/Kitware/CMake.git
cd CMake
./bootstrap --prefix=/usr/local && make  -j8&& sudo make install
#sudo rm -rf  ../CMake
sudo mv ../CMake  ~/pkg