#!/bin/sh 
../../32binary ~/Data/DBpedia/graph/dbpedia.e temp/dbpedia.adj
mpirun ./xtrapulp temp/dbpedia.adj 10 -o temp/dbpedia.part
