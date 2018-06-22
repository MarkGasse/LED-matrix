#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "ostream" 
#include "ledmatrix.hpp"
#include "vector"
#include "string"
using namespace std;

class snake {
private:
	ledmatrix & m;
	int direction;
	int tailSize;
	int snakeX[64];
	int snakeY[64];
public:
	snake(ledmatrix & m, int & direction, int tailSize):
	m( m ),
	direction( direction ),
	tailSize( tailSize )
	{
		snakeX[0] = 1;
		snakeY[0] = 1;
	}
	
	void draw();
	void update();
	void gameover();
};

#endif //SNAKE_HPP