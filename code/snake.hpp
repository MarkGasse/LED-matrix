#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "ostream" 
#include "ledmatrix.hpp"
#include "fruit.hpp"
#include "vector"
#include "string"
using namespace std;

class snake {
private:
	ledmatrix & m;
	fruit & f;
	int direction;
	int tailSize;
	int snakeX[64];
	int snakeY[64];
	int score[3] = {0,0};
public:
	snake(ledmatrix & m, fruit & f, int & direction, int tailSize):
	m( m ),
	f( f ),
	direction( direction ),
	tailSize( tailSize )
	{
		snakeX[0] = 1;
		snakeY[0] = 1;
	}
	
	void draw(int state);
	void update(int direction);
	void checkFruit();
	void points();
	void gameover();
};

#endif //SNAKE_HPP