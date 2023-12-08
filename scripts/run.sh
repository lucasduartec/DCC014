#!/bin/bash
cd build
make clean
make
clear
./main
cd ..
cd images
cd dot
dot -Kfdp -n -Tpng -o ../labirinto.png graph.dot
dot -Tpng tree.dot -o ../arvore.png