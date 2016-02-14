#include "City.h"
#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main(int argc, char **argv){
	Graph g;
	string filename(argv[1]);
	const char * c = filename.c_str();
	fstream x(c);
	while (!x.eof()){
		int numCities;
		x >> numCities;
		g.allocateMatrix(numCities);
		for (int i = 0; i < numCities; i++){
			string name;
			x >> name;
			City c(name);
			g.reference.push_back(c);
		}
		int numFlights;
		x >> numFlights;
		for (int a = 0; a < numFlights; a++){
			int fromIndex, toIndex;
			string from, to;
			x >> from;
			x >> to;
			fromIndex = g.findIndex(from);
			toIndex = g.findIndex(to);
			g.matrix[fromIndex][toIndex] = 1;
		}
	}
	
	for (int i = 0; i < g.getNumCities(); i++){
		for (int j = 0; j < g.getNumCities(); j++){
			cout << "[" << g.matrix[i][j] << "] ";
		}
		cout << endl;
	}
	
	vector<string> parameters;
	string in;
	cout << "submit query [HOME <city name>, TRAVEL <city 1> <city 2>]: " << endl;
	getline(cin, in);
	istringstream iss(in);
	do
	{
		string sub;
		iss >> sub;
		parameters.push_back(sub);

	}while(iss);
	
	if (parameters[0] == "HOME"){
		int h = g.findIndex(parameters[1]);
		City home = g.reference[h];
		g.homePath(home);		
	} else if (parameters[0] == "TRAVEL"){
		int h1 = g.findIndex(parameters[1]);
		int h2 = g.findIndex(parameters[2]);
		City c1 = g.reference[h1];
		City c2 = g.reference[h2];
		g.travel(c1, c2);
	}
	
}
