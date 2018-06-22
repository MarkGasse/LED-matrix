#include "fruit.hpp"

void fruit::draw(){
	// writing fruits position
	m.write_pixel(fx,fy,1);
	m.write_pixel(fx,fy,0);
}

void fruit::update(){
	int z = rand() % 7 + 1;
	fx = z; fy = z;
}

void win(){
	
}