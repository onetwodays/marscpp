cd ../pkg
tar -zxvf libev-4.31.tar.gz
cd libev-4.31
./configure && make -j8 && sudo make install

cd ..
mv libev-4.31 ~/pkg/
