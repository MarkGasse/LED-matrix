// ==========================================================================
//
// File      : fruit.cpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : mark.gasse@student.hu.nl 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
#include "fruit.hpp"

// set the position of the x and y coordinates to to 1 or 0 
// Based on the state of the draw function
void fruit::draw(int state){
	if(state == 1){
		m.setpixel(fx,fy,1);
	}else{
		m.setpixel(fx,fy,0);
	}
}

// updates de x and y coordinates of the fruit to a new value
void fruit::update(){
	fx = rand() % maxX + 1;
	fy = rand() % maxY + 1;
}

// get function
// other classes can get the private value fx
int fruit::getFX(){
	return fx;
}

// other classes can get the private value fy
int fruit::getFY(){
	return fy;
}

