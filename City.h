#ifndef _City_H_
#define _City_H_
#include <string>
#include <climits>
using namespace std;
class City;

enum Color {WHITE, GRAY, BLACK};

class City{

	private:
		string name;
		Color color;
		int distance;
		City* pi;
	
	public:
		City(string n);
		City();
		string getName();
		Color getColor();
		void setColor(Color co);
		int getDistance();
		void setDistance(int di);
		void setPi(City* p);
		City* getPi();
};


#endif
