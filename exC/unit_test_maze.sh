#!/bin/bash
# $Id: unit_test_maze.sh 2957 2011-11-20 16:21:43Z marechal $
# unit tests for preprocessor assignment

if test $# -eq 0 ; then
echo "Uage : $0 C_source_filename"
exit
fi
echo "Source : $1.c"
echo "without size value"
gcc -o $1 $1.c
./$1
echo "-----------------------------"
echo "with -2"
gcc -DMAZE_REQ_SIZE=-2 -O $1 $1.c
./$1
echo "-----------------------------"
echo "with -1"
gcc -DMAZE_REQ_SIZE=-1 -O $1 $1.c
./$1
echo "-----------------------------"
echo "with 0"
gcc -DMAZE_REQ_SIZE=0 -O $1 $1.c
./$1
echo "-----------------------------"
echo "with 1"
gcc -DMAZE_REQ_SIZE=1 -O $1 $1.c
./$1
echo "-----------------------------"
echo "with 2"
gcc -DMAZE_REQ_SIZE=2 -O $1 $1.c
./$1
echo "-----------------------------"
echo "with 10"
gcc -DMAZE_REQ_SIZE=10 -O $1 $1.c
./$1
echo "-----------------------------"
echo "with 101"
gcc -DMAZE_REQ_SIZE=101 -O $1 $1.c
./$1