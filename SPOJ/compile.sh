#!/bin/bash

echo "Compiling $1..."
g++ -O2 -o $1/$1 $1/$1.cpp -std=c++11
echo "Done.."

#@created by mahmud.cse15@gmail.com