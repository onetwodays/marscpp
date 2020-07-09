#!/usr/bin/env bash

sudo apt-get install        libgflags-dev  \
&& sudo apt-get install -y  libsnappy-dev  \
&& sudo apt-get install -y  zlib1g-dev     \
&& sudo apt-get install -y  libbz2-dev      \
&& sudo apt-get install -y  libzstd-dev
