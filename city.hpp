/**************************************************************************************************************
** Program name: Final Group Project
** Author: Derrick Li and Juan Du
** Date: Aug. 18, 2017
** Description:
** Defines city struct and accessory helper functions.
***************************************************************************************************************/

#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include <fstream>

struct city {
	int id;
	int x;
	int y;
};

int calculateTSPDistance(int nVertices, int **adj, std::vector<int> path);
void printToOutput(int dist, std::vector<int> path, std::ofstream &outputFile);

#endif