#!/bin/sh
set -e

cd "$(dirname "$0")"
cc -std=c99 -Wall -Wextra -pedantic -c MyStacks.c -o MyStacks.o
ar rcs libStack.a MyStacks.o
cc -std=c99 -Wall -Wextra -pedantic MainP.c ./libStack.a -o demo
./demo
