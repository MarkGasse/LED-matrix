#include "snake.hpp"

void snake::draw(int state){
	// writing snakes position

	for(int i = 0; i < tailSize; i++){
		if(state == 1){
			m.setpixel(snakeX[i],snakeY[i],1);
			
		}else{
			m.setpixel(snakeX[i],snakeY[i],0);
		}

	}
}

// swapping snake end with snake position
void snake::update(int direction){
	// last tail position x and y
	int tailEndX = snakeX[0]; 
	int tailEndY = snakeY[0];
	int tmpx; int tmpy;
	for(int k = 0; k < tailSize; k++){
	   tmpx = snakeX[k]; 
	   tmpy = snakeY[k];
	   snakeX[k] = tailEndX; 
	   snakeY[k] = tailEndY;
	   tailEndX = tmpx; 
	   tailEndY = tmpy;
	}
	
	// moving the snake every update
	if(direction == 1){snakeX[0] += 1;}
	if(direction == 2){snakeX[0] -= 1;}
	if(direction == 3){snakeY[0] += 1;}
	if(direction == 4){snakeY[0] -= 1;}
	//snake::gameover();
	
	if(snakeX[0] == 9 || snakeX[0] == 0 || snakeY[0] == 9 || snakeY[0] == 0 /*|| snakeX[1] == tmpx || snakeY[1] == tmpy*/ ){
		gameover();
	}
}


void snake::checkFruit(){
	if(snakeX[0] == f.getFX() && snakeY[0] == f.getFY()){
		f.update();
		tailSize++;
	}
}

//check gameover
void snake::gameover(){
	//if(snakeX[0] == 9 || snakeX[0] == 0 || snakeY[0] == 9 || snakeY[0] == 0){
		m.clear_all();
		m.intensity(2);
		m.write_all(35);
		hwlib::wait_ms( 10000 );
		m.clear_all();

	//}
}