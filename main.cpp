/**************************************************************************************************************
** Program name: Final Group Project
** Author: Derrick Li and Juan Du
** Date: Aug. 18, 2017
** Description:
** Implementation of TSP.
***************************************************************************************************************/

#include "city.hpp"
#include "christofides.hpp"

#include <iostream>
#include <fstream>	/* ofstream, ifstream */
#include <string>
#include <vector>
#include <sstream> 	/* istringstream */
#include <cmath> 	/* round, hypot */
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

using std::ifstream;
using std::ofstream;

using std::string;
using std::vector;
using std::istringstream;

int main(int argc, char* argv[])
{
	clock_t start_time = clock();		// Start timer

	// Assert filename is supplied as command line argument
	if (argc <= 1)
	{
		cout << endl << "Please supply the file name of the graph input as a command line argument." << endl << endl;
		return 1;
	}

	// Open input file
	ifstream inputFile;
	string inputFileName = argv[1];
	inputFile.open(inputFileName);

	if (inputFile.fail())	// Error opening file
	{
		cout << endl << "Error in opening file \"" << inputFileName << "\"." << endl << endl;
	}
	else	// Else, read in city id, and x- and y-coordinates, and run TSP solver
	{

		// Create output file to write to; output filename will be the input filename with ".tour" appended
		string outputFileName = inputFileName + ".tour";
		ofstream outputFile;
		outputFile.open(outputFileName);

		int cityCount = 0;			// Number of cities
		vector<city> cityVector;	// Vector of all cities read from inputfile
		vector<int> path;			// A vector of the path calculated by Christofides' and Two-Opt
		int dist = 0;				// The distance to travel all cities calculated from `path`

		// Read in all city id, and x- and y-coordinates from input file and put into vector of city structs
		string readString;
		while (getline(inputFile, readString))
		{
			if (readString.empty())   /* Empty lines in input file are skipped */
			{
				continue;
			}

			/* Each line is read into a string, constructed into an istringstream, and
			   parsed and read into the temp struct members which is then pushed to cityVector */

			istringstream readIss(readString);
			int extractedInt;

			city temp;

			readIss >> extractedInt;
			temp.id = extractedInt;

			readIss >> extractedInt;
			temp.x = extractedInt;

			readIss >> extractedInt;
			temp.y = extractedInt;

			cityVector.push_back(temp);
			cityCount++;
		}

		/* Creates adjacency matrix. adj[i][j] - distance from city i to city j */
		int **adj = new int*[cityCount];
		for (int i = 0; i < cityCount; i++)
		{
			adj[i] = new int[cityCount];
		}

		for (int i = 0; i < cityCount; i++)
		{
			for (int j = i; j < cityCount; j++) /* adj matrix mirrors across diagonal */
			{
				adj[i][j] = adj[j][i] = round(hypot(cityVector[i].x - cityVector[j].x, cityVector[i].y - cityVector[j].y));
			}
		}

        /* Run the Christofides' Algorithm */
		cout << endl << "Running the Christofides' Algorithm..." << endl;
		path = christofides(cityCount, adj);

		/* Then run the 2-Opt Algorithm */
		cout << "Then the 2-Opt Algorithm..." << endl;
		path = twoOpt(cityCount, path, adj);

		/* Calculate distance */
		dist = calculateTSPDistance(cityCount, adj, path);

		/* Print path to outputfile */
		printToOutput(dist, path, outputFile);

		/* Cleans up adj matrix */
		for (int i = 0; i < cityCount; i++)
		{
			delete[] adj[i];
		}
		delete[] adj;

		/* Close input and output files */
		inputFile.close();
		outputFile.close();

		/* Print distance to screen */
		cout << endl << "Calculated TSP distance: " << dist << endl;
		cout << "Results are written to \"" << outputFileName << "\"." << endl << endl;
	}

	// Stop timer and print out total run time
	clock_t end_time = clock();
	double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "Total run time: " << elapsed_time << " secs." << endl;

	return 0;
}
