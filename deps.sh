#!/bin/bash

git clone https://github.com/y21/optparse --quiet
mv optparse/include ./include
rm -rf optparse
echo "downloaded dependencies. you can now link against include/"