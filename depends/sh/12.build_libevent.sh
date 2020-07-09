cd ../pkg
tar -zxvf libevent-2.1.11-stable.tar.gz
cd libevent-2.1.11-stable
./configure && make -j8 && sudo make install

cd ..
mv libevent-2.1.11-stable  ~/pkg/
