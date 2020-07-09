#!/usr/bin/env bash
#7z文件到解压缩实例
#——————————————————————————————————-
#安装：Redhat、Fedora、Centos安装命令：yum install p7zip
#安装：Debian、Ubuntu安装命令：apt-get install p7zip
#——————————————————————————————————–
#解压实例：
#7z x filename.7z

#sudo yum install p7zip
#sudo apt install p7zip

BOOST_PACKAGE="boost_1_70.0.tar.gz"
BOOST="boost_1_70_0"
cd  ../pkg/ \
&& tar -xzvf  ${BOOST_PACKAGE}  \
&& cd  ${BOOST} \
&& ./bootstrap.sh \
&& sudo ./b2 link=static install   \
&& cd ..
&& sudo  mv ${BOOST}   ~/pkg/
#&& rm -rf   ../boost_1_72_0/

