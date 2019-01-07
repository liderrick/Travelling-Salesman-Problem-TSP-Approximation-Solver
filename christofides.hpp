/**************************************************************************************************************
** Program name: Final Group Project
** Author: Derrick Li and Juan Du
** Date: Aug. 18, 2017
** Description: Specification file of Christofides and 2-Opt Algorithm for TSP
***************************************************************************************************************/

#ifndef CHRISTOFIDES_HPP
#define CHRISTOFIDES_HPP

#include <vector>
#include <string>
#include <fstream>

struct vertexAttributes {
	int id;
	int key;
	int parent;
	bool inQueue;
};

struct eulerAttributes {
	int id;
	int numEdges;
	bool isVisited;
};

struct comparator;

int** init2DArray(int nVertices);
void delete2DArray(int nVertices, int** arr);
void cleanup(int nVertices, int** mst, int** mwpm, int** cmg);

std::vector<int> christofides(int nVertices, int **adj);
int** MSTPrim(int nVertices, int **adj, int root);
int** minCostPerfectMatching(int nVertices, int **adj, int **mst);
int** combineMSTandMWPM(int nVertices, int **mst, int** mwpm);
std::vector<int> findEulerTourAndShortcut(int nVertices, int** cmg);

std::vector<int> twoOpt(int nVertices, std::vector<int> hamList, int **adj);
std::vector<int> twoOptSwap(int nVertices, std::vector<int> hamList, int i, int k);

#endif
