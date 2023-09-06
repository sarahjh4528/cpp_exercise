#!/bin/bash

_help()
{
cat 1>&1 << HELP_EOT

To run:
    ./genX.sh <options>

    Options:
    -c  Clean executable and object file
    -g  Compile debug version
    -x  Generate executable file

HELP_EOT
}

while getopts "cgx" option
do
    case ${option} in
        c) echo "rm -f test *.o"
            rm -f test *.o
            ;;
        g) echo "g++ -std=c++17 -g -Wall -Wextra main.cpp -o test"
            g++ -std=c++17 -g -Wall -Wextra main.cpp -o test
            ;;
        x) echo "g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o test"
            g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o test
            ;;
        ?) _help
            ;;
    esac
done
