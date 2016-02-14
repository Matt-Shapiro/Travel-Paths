#include "Graph.h"

void Graph::allocateMatrix(int numCities){
	this -> numCities = numCities;
	matrix = new int*[numCities];
	for (int i = 0; i < numCities ; i++){
		matrix[i] = new int[numCities];
	}
	for (int i = 0; i < numCities; i++){
		matrix[0][0] = 0;
	}
}

int Graph::getNumCities(){
	return numCities;
}

int Graph::findIndex(string s){
	for (int i = 0; i < reference.size(); i++){
		if (s == reference[i].getName())
			return i;
	}
}

void Graph::homePath(City home){
	bool foundHome = false;
	home.setColor(GRAY);
	home.setDistance(0);
	home.setPi(NULL);
	queue<City> Q;
	Q.push(home);
	while (!Q.empty()){
		int f = findIndex(Q.front().getName());
		for (int i = 0; i < reference.size(); i++){
			if (matrix[f][i] == 1){ //if there is a path to this city
				if (reference[i].getName() == home.getName()){
					foundHome = true;
					stack<string> output;
					cout << reference[i].getName() << ' ';
					City* cp;
					for (cp = &Q.front(); cp -> getPi() != NULL; cp = cp -> getPi()){
						output.push(cp -> getName());
					}	
					for (int z = 0; z < Q.front().getDistance(); z++){
						cout << output.top() << ' ';
						output.pop();
					}
					cout << home.getName() << endl;
				} else if (reference[i].getColor() == WHITE){
					reference[i].setColor(GRAY);
					reference[i].setDistance(Q.front().getDistance() + 1);
					reference[i].setPi(&Q.front()); 
					Q.push(reference[i]);
				}
			}
		}
		Q.front().setColor(BLACK);
		Q.pop();
	}
	if (!foundHome)
		cout << "no" << endl;	
}

void Graph::travel(City c1, City c2){
	bool foundCity;
	c1.setColor(GRAY);
	c1.setPi(NULL);
	c1.setDistance(0);
	queue<City> Q;
	Q.push(c1);
	while(!Q.empty()){
		int f = findIndex(Q.front().getName());
		for (int i = 0; i < reference.size(); i++){
			if (matrix[f][i] == 1){
				if (reference[i].getName() == c2.getName()){
					foundCity = true;
					stack<string> output;
					City* cp;
					cout << c1.getName() << ' ';
					for (cp = &Q.front(); cp -> getPi()!= NULL; cp = cp -> getPi()){
						output.push(cp -> getName());
					}
					for (int d = 0; d < Q.front().getDistance(); d++){
						cout << output.top() << ' ';
						output.pop();
					}
					cout << c2.getName() << endl;
				} else if (reference[i].getColor() == WHITE){
					reference[i].setColor(GRAY);
					reference[i].setDistance(Q.front().getDistance() + 1);
					reference[i].setPi(&Q.front());
					Q.push(reference[i]);
				}
			}
		}
		Q.pop();
	}
	if (!foundCity)
		cout << "no" << endl;
}


	

