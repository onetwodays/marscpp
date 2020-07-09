#!/usr/bin/env bash
cd ../pkg
tar zxvf   jansson-2.12.tar.gz
cd jansson-2.12

./configure && make -j8 && sudo make install

cd ..
mv jansson-2.12 ~/pkg/


