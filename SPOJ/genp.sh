#!/bin/bash

#echo "===Enter Platform Name==="
#read platform
#echo "====Enter Problem Name===="
#read pname
# arg1 = problem name arg2= no of input files

rm -rf $1
echo "===Problem : $1==="
mkdir $1
cd $1
touch $1.cpp
cat ../template.cpp >> $1.cpp

for((i=1;i<=$2;i++))
do
  #echo "Creating $1.in$i..."
  touch $1.in$i
  touch $1.out$i
done
echo "=================="
#pwd
#ls

#@created by mahmud.cse15@gmail.com
