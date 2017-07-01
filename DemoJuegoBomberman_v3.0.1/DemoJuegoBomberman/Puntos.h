#ifndef __PUNTOS_H__
#define __PUNTOS_H__
#include <sstream>
#include <string>
using namespace std;
class Puntos {
	int x, y;
public:
	Puntos(int x = 0, int y = 0) :x(x), y(y) {}

	int getX(){ return x; }
	int getY(){ return y; }
	
	std::string toString() {
		std::ostringstream ss;
		ss << "P(";
		ss << x;
		ss << " , ";
		ss << y;
		ss << ")";
		return (ss.str());
	};
};
#endif