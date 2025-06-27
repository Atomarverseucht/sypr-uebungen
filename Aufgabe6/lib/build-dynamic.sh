#!/bin/bash
for s in notenspiegel benotung fachnote fachnoten_liste; do
    compile_command="g++ -g -fPIC -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -c -o $s.o ../../Aufgabe5/$s.cpp -I../../Aufgabe5"
    echo $compile_command
    eval $compile_command
    if [ $? -ne 0 ]; then
        echo Build failed
        exit 1
    fi
done
compile_command="g++ -fPIC -shared -o libaufgabe6.so *.o"
echo $compile_command
eval $compile_command
if [ $? -ne 0 ]; then
    echo Build failed
    exit 1
fi
echo Build successfull