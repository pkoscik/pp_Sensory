#!/bin/bash

echo "[runner] Running script in a verbose mode"
echo "[runner] Compiling TeX files using compile_all_docker.py"
python3 compile_all_docker.py

echo "[runner] Merging all files using merge_all.py"
python3 merge_all.py

echo "[runner] Compressing all files using compress.sh"
./compress.sh

echo "[runner] Removing uncompressed file"
rm out.pdf
