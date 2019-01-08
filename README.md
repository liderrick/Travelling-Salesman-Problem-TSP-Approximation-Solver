# Travelling Salesman Problem (TSP) Approximation Solver

This program is an approximation solver for the [travelling salesman problem (TSP)](https://en.wikipedia.org/wiki/Travelling_salesman_problem) coded in C++. The approximation solver uses two approximation algorithms in tandem to generate its solution: [Christofides algorithm](https://en.wikipedia.org/wiki/Christofides_algorithm) followed by [2-opt](https://en.wikipedia.org/wiki/2-opt).

The program's implementation of the [Christofides algorithm](https://en.wikipedia.org/wiki/Christofides_algorithm) has the advantage of speed, but doesn't quite consistently guarantee the [1.5 approximation ratio](https://en.wikipedia.org/wiki/Christofides_algorithm#Approximation_ratio) in its solution. This is due to the greedy approach taken in implementing the generation of the [minimum weight perfect matching (MWPM) graph](https://en.wikipedia.org/wiki/Matching_(graph_theory)#Definition) as part of the [Christofides algorithm](https://en.wikipedia.org/wiki/Christofides_algorithm). Most of the program's computation is spent in the [2-opt](https://en.wikipedia.org/wiki/2-opt) algorithm to compensate for this deficiency.

* The input file is a list of cities. Each line states the city's identifier, x-coordinate, and y-coordinate. Each value is an integer and is separated from one another by a single whitespace.

* The output file contains the generated solution using the [Christofides algorithm](https://en.wikipedia.org/wiki/Christofides_algorithm) and [2-opt](https://en.wikipedia.org/wiki/2-opt): the total path length is in its first line, followed by an ordered list of the cities' identifiers.

Some example input files are provided. These `test-input-#.txt` files were sourced from Oregon State University, CS 325 - Summer 2017.

## Instructions
1. Run `make` to compile solver.
2. Run `solver.exe <input_filename>` to run solver on input file, e.g. `solver.exe test-input-1.txt`.

## Acknowledgements
The code shown is my individual contribution to a larger project which uses multiple TSP approximation algorithms. Project was performed in collaboration with Juan Du.

