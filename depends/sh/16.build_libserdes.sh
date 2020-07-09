#!/usr/bin/env bash
git clone https://github.com/confluentinc/libserdes.git

cd libserdes && ./configure && make -j8 && sudo make install

cd ..
mv libserdes ~/pkg/

