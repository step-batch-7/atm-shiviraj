#! /bin/bash

echo "compling..."​​
rm -rf *.o
gcc -c *.c
gcc -o atm *.o
rm -rf *.o
echo "done"
./atm
rm -rf atm