#include "snake.hpp"

// set the position of the x and y coordinates to to 1 or 0 
// Based on the state of the draw function
// And repeats this for all tail parts 
void snake::draw(int state){
	for(int i = 0; i < tailSize; i++){
		if(state == 1){
			m.setpixel(snakeX[i],snakeY[i],1);
		}else{
			m.setpixel(snakeX[i],snakeY[i],0);
		}
	}
}

// updates the direction and tail
// checks the conditions of the game
void snake::update(int direction){
	// last tail position x and y   
	int tailEndX = snakeX[0]; 
	int tailEndY = snakeY[0];
	
	// swapping tail positon k with snakeHead position
	for(int k = 0; k < tailSize; k++){
	   int tmpx = snakeX[k]; 
	   int tmpy = snakeY[k];
	   snakeX[k] = tailEndX; 
	   snakeY[k] = tailEndY;
	   tailEndX = tmpx; 
	   tailEndY = tmpy;
	   
	   // checks if snakeHead is in tail
	   if(tailSize > 1 && snakeX[0] == snakeX[k+1] && snakeY[0] == snakeY[k+1]){
		gameover();
	   }
	}
	
	// change moving direction of snake
	if(direction == 1){snakeX[0] += 1;}
	if(direction == 2){snakeX[0] -= 1;}
	if(direction == 3){snakeY[0] += 1;}
	if(direction == 4){snakeY[0] -= 1;}
	
	// checks if snakehead is between the borders of the led display
	if(snakeX[0] == 9 || snakeX[0] == 0 || snakeY[0] == 9 || snakeY[0] == 0 ){
		gameover();
	}
}

// check if snakeHead has the same position as the fruit
// updates fruit and tailSize
void snake::checkFruit(){
	if(snakeX[0] == f.getFX() && snakeY[0] == f.getFY()){
		f.update();
		tailSize++;
	}
}

// gameover animation
void snake::gameover(){
		m.clear_all();
		m.intensity(2);
		m.write_all(35);
		hwlib::wait_ms( 10000 );
		m.clear_all();
}