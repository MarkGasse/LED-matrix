// ==========================================================================
//
// File      : snake.cpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : mark.gasse@student.hu.nl 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
#include "snake.hpp"

// set the position of the x and y coordinates to 1 or to 0 
// based on the state of the draw function
// repeats this for all tail parts 
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
	// snakehead position x and y   
	int tailEndX = snakeX[0]; 
	int tailEndY = snakeY[0];
	
	// swapping the new tail end with the previous tail end as long as k is smaller then tailSize
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
// updates fruit, tailSize and score
void snake::checkFruit(){
	if(snakeX[0] == f.getFX() && snakeY[0] == f.getFY()){
		f.update();
		tailSize++;
		if(score[1] == 9){
			score[0]++;
			score[1] = 0;
		}
		score[1]++;
		
	}
}

// show score on led matrix
void snake::points(){
	m.digits(0,score[0]);
	m.digits(4,score[1]);
}

// gameover animation
void snake::gameover(){
		m.clear_all();
		m.intensity(2);
		m.write_all(35);
		m.clear_all();
		points();
		hwlib::wait_ms( 10000 );
}