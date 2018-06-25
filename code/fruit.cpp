#include "fruit.hpp"

void fruit::draw(int state){
	// writing fruits position
	if(state == 1){
		m.setpixel(fx,fy,1);
	}else{
		m.setpixel(fx,fy,0);
	}
	

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

