#include "City.h"
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Graph{
	
	private:
		int numCities;
	
	public:
		void allocateMatrix(int numCities);
		int** matrix;
		vector<City> reference;
		int getNumCities();
		void homePath(City home);
		void travel(City c1, City c2);
		int findIndex(string s);
};
