set -e
#git clone https://github.com/curl/curl.git 不要从github l拉代码,不稳定
#wget https://curl.haxx.se/download/curl-7.68.0.tar.gz
cd ../pkg
tar -xzvf curl-7.68.0.tar.gz
cd curl-7.68.0
./configure && make  -j8 && sudo make install
#sudo rm -rf  ../curl
cd ..
sudo mv -f curl-7.68.0 ~/pkg/
#sudo mv curl-7.68.0.tar.gz depends/