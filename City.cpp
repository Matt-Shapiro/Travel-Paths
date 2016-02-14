#include "City.h"

City::City(string n){
	name = n;
	distance = INT_MAX;
	pi = NULL;
	color = WHITE;
}

City::City(){
}

string City::getName(){
	return name;
}

Color City::getColor(){
	return color;
}
void City::setColor(Color co){
	color = co;
}
int City::getDistance(){
	return distance;
}
void City::setDistance(int di){
	distance = di;
}
void City::setPi(City* p){
	pi = p;
}
City* City::getPi(){
	return pi;
}