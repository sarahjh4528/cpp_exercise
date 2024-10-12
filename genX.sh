#!/bin/bash

_help()
{
cat 1>&1 << HELP_EOT

To run:
    ./genX.sh <options>

    Options:
    -c  Clean executable and object file
    -g  Compile main.cpp
    -s  Compile sample.cpp

HELP_EOT
}

while getopts "cgx" option
do
    case ${option} in
        c) echo "rm -f test *.o"
            rm -f *test* *.o
            ;;
        g) echo "g++ -std=c++17 -g main.cpp -o test"
            g++ -std=c++17 -g main.cpp -o test
            ;;
        x) echo "g++ -std=c++17 -g sample.cpp -o stest"
            g++ -std=c++17 -g sample.cpp -o stest
            ;;
        ?) _help
            ;;
    esac
done
