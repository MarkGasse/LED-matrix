// ==========================================================================
//
// File      : fruit.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : mark.gasse@student.hu.nl 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
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
	
	void draw(int state);
	void update();
	int getFX();
	int getFY();
};

#endif //FRUIT_HPP