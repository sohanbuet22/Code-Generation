#!/bin/bash

if command -v antlr4 >/dev/null 2>&1; then
    antlr4 -v 4.13.2 -Dlanguage=Cpp -visitor -no-listener CSubset.g4
else
    echo "antlr4 not found; using the checked-in generated parser sources." >&2
fi
g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime *.cpp -L/usr/local/lib/ -lantlr4-runtime -pthread -o compiler.out
LD_LIBRARY_PATH=/usr/local/lib ./compiler.out $1
