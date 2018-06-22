#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "ledmatrix.hpp"

class fruit {
private:
	ledmatrix & m;
	int fx;
	int fy;
public:
	fruit(ledmatrix & m, int fruitX, int fruitY):
	m( m ),
	fx( fruitX ),
	fy( fruitY )
	{}
	
	void draw();
	void update();
	void win();
};

#endif //FRUIT_HPP