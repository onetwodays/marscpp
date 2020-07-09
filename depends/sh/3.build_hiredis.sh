#!/usr/bin/env bash


cd  ../pkg/hiredis \
&& make $* \
&& sudo cp -r -f libhiredis.a  /usr/local/lib    \
&& sudo cp -r -f ../hiredis/   /usr/local/include \
&& make clean
