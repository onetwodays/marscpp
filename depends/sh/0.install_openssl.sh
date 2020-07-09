#包安装,建议

#apt install openssl libssl-dev -y

#包卸载
#sudo apt-get purge openssl
#sudo rm -rf /etc/ssl #删除配置文件


#wget https://www.openssl.org/source/openssl-1.1.1d.tar.gz
#prefix 是安装目录，openssldir 是配置文件目录
cd ../pkg
tar -xvf openssl-1.1.1d.tar.gz
cd openssl-1.1.1d
./config  --prefix=/usr/local/openssl-1.1.1b
make  -j8 && sudo make install
openssl version -a
cd ..
sudo mv -f  openssl-1.1.1d  ~/pkg/
sudo rm -rf openssl-1.1.1d
#mv openssl-1.1.1d.tar.gz depends/

