#!/bin/bash
cd build
make clean
make
./main
cd ..
dot -Kfdp -n -Tpng -o grafo.png graph.dot
dot -Tpng tree.dot -o arvore.png