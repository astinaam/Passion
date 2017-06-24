#!/bin/bash

clear
echo "Compiling $1..."
g++ -O2 -o $1/$1 $1/$1.cpp -std=c++11
echo "Done.."
echo "============Running=============="

#time ./$1 < $1.in > $1.out

for((i=1;i<=$2;i++))
do
  echo "==========debugging test $i==========="
  #time ./$1/$1 < $1/$1.in$i > $1/$1.out$i
  ./$1/$1 < $1/$1.in$i > $1/$1.out$i 2> $1/err.log
done

echo ""
echo "============Output=============="
for((i=1;i<=$2;i++))
do
  echo "==========Test $i============="
  cat $1/$1.out$i
  #echo "=============================="
  #echo ""
done
echo "============Finished============="
echo ""

#@created by mahmud.cse15@gmail.com
