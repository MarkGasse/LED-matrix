#include "fruit.hpp"

void fruit::draw(){
	// writing fruits position
	m.write_pixel(fx,fy,1);
	m.write_pixel(fx,fy,0);
}

void fruit::update(){
	fx = rand() % maxX + 1;
	fy = rand() % maxY + 1;
}

int fruit::getFX(){
	return fx;
}

int fruit::getFY(){
	return fy;
}

