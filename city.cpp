/**************************************************************************************************************
** Program name: Final Group Project
** Author: Derrick Li and Juan Du
** Date: Aug. 18, 2017
** Description:
** Accessory functions to calculate TSP distance and print to file.
***************************************************************************************************************/

#include "city.hpp"

#include <iostream>
#include <vector> 	/* vector */
#include <fstream> 	/* ofstream */

using std::endl;
using std::cout;
using std::cin;

using std::vector;

using std::ofstream;

/***************************************************************************************************************
** Description: Calculates the TSP distance from list of vertices.
** @param: nVertices - number of vertices (rows/colums) in adjacency matrix
** @param: adj - adjacency matrix
** @param: path - a vector of ordered vertices representing the TSP path
** @return: TSP distance calculated from path
***************************************************************************************************************/
int calculateTSPDistance(int nVertices, int **adj, vector<int> path)
{
	int dist = 0;

	for (int i = 0; i < nVertices; i++)
	{
		int u = path.at(i);
		int v;

		if (i + 1 < nVertices)
		{
			v = path.at(i + 1);
		}
		else
		{
			v = path.at(0);
		}

		dist += adj[u][v];
	}

	return dist;
}

/***************************************************************************************************************
** Description: Prints distance and list of vertices to file
** @param: dist - TSP distance calculated from path
** @param: path - a vector of ordered vertices representing the TSP path
** @param: outputFile - the ofstream object to print the distance and path to
** @return: void
***************************************************************************************************************/
void printToOutput(int dist, vector<int> path, ofstream &outputFile)
{
	outputFile << dist << endl;

	for (int i = 0; i < (signed)path.size(); i++)
	{
		outputFile << path.at(i) << endl;
	}
}