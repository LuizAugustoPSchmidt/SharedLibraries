#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Please input the header name without the '.h'"
  exit 1
fi

gcc -c -fPIC "$1".c -o "$1".o &&

gcc -shared "$1" -o lib"$1".so &&

sudo cp lib"$1".so /usr/lib/ &&

sudo cp "$1".h /usr/include/ &&

sudo ldconfig




