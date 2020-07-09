#!/usr/bin/env bash
mkdir -p tt
cd tt/
git clone https://github.com/google/double-conversion.git
cd double-conversion
cmake -DBUILD_SHARED_LIBS=ON .
make
sudo make install
rm -rf tt
