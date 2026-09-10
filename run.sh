#!/bin/bash

set -e

source venv/bin/activate

./run-script.sh input.txt

fasm code.asm code_bin

./code_bin

