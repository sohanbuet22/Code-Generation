#!/bin/bash
g++ -std=c++17 -Wall -Wextra -o 2205047 2205047_symbol_table.cpp
if [ $? -eq 0 ]; then
    echo "Build successful. Run with: ./2205047 <input_file> <output_file>"
else
    echo "Build failed."
    exit 1
fi
