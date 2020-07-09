#!/usr/bin/env bash
cd ../pkg
tar -zxvf mpdecimal-2.4.2.tar.gz
cd mpdecimal-2.4.2
./configure && make -j8 && sudo make install

cd ..
mv mpdecimal-2.4.2 ~/pkg/
