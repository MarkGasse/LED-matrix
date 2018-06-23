#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "ledmatrix.hpp"

class fruit {
private:
	ledmatrix & m;
	int maxX;
	int maxY;
	int fx;
	int fy;
public:
	fruit(ledmatrix & m,int maxX, int maxY, int fruitX, int fruitY):
	m( m ),
	maxX( maxX ),
	maxY( maxY ),
	fx( fruitX ),
	fy( fruitY )
	{}
	
	void draw();
	void update();
	int getFX();
	int getFY();
};

#endif //FRUIT_HPP