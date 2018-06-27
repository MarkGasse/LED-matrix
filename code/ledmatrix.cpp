// ==========================================================================
//
// File      : ledmatrix.cpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : mark.gasse@student.hu.nl 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

#include "ledmatrix.hpp"

void ledmatrix::setup(){
	//uint8_t position[2] = {0x0F , 0x0F};      // test mode off
	//bus.write_and_read( load, 2, position, nullptr );
	
	// define value to use ledmatrix
	uint8_t position [2] = {};
	position[0] =  0x0C; position[1] =  0x00 ; // shutdownmode = 0
	bus.write_and_read( load, 2, position, nullptr );

	intensity(5); // set intensity

	position[0] =  0x09; position[1] =  0x00 ;    // decode mode       mode of display       
	bus.write_and_read( load, 2, position, nullptr );

	uint8_t size = 0x01 * (maxX - 1);
	position[0] =  0x0b; position[1] =  size ;         // led size x      
	bus.write_and_read( load, 2, position, nullptr );

	clear_all(); // set all leds off 

	position[0] =  0x0C; position[1] =  0x01 ;  // shutdownmode = 1
	bus.write_and_read( load, 2, position, nullptr );

}

void ledmatrix::setpixel(int x, int y, bool state){
	if(state == 1){
		rows[x-1] = 1;
		koloms[x-1] |= (1 << (y - 1));
	}else{
		rows[x-1] = 0;
		koloms[x-1] &= ~(1 << (y - 1));
	}
}

void ledmatrix::writepixels(){
	uint8_t position [2] = {};
	for(int a = 0; a < 8; a++){
		if(rows[a] == 1){
			position[0] =  0x01 * a+1; position[1] =  koloms[a] ;
		}else{
			position[0] =  0x01 * a+1; position[1] =  0x00 ;
		}
		bus.write_and_read( load, 2, position, nullptr );
	}


}

void ledmatrix::intensity(int brithness){
	 
	uint8_t position [2] = {};
	uint8_t bn = 0x01 * brithness;
	position[0] =  0x0A; position[1] =  bn ;               
	bus.write_and_read( load, 2, position, nullptr );
}

void ledmatrix::clear_all(){
	for( int j = 1; j <= maxX ; j++){
		for(int i = 0; i <= maxY; i++){
			setpixel(j,i,0);
			writepixels();
		}
	}
}

void ledmatrix::write_all(int ms){
	//turn all leds on
	for( int j = 1; j <= maxX ; j++){
		for(int i = 0; i <= maxY; i++){
			setpixel(j,i,1);
			writepixels();
			hwlib::wait_ms( ms );
		}
	}
	
}

void ledmatrix::write_pixel(int  x, int  y, bool value){
	if(x <= maxX && y <= maxY){
		uint8_t position [2] = {};
		uint8_t row = 0x01 * x;
		
		if(value == 1){
			kolom |= (1 << (y - 1));
		}else{
			kolom &= ~(1 << (y - 1));
		}
		
		position[0] =  row; position[1] =  kolom ;         // position y         
		bus.write_and_read( load, 2, position, nullptr );

		//position[0] =  0x0C; position[1] =  0x01 ;         // shutdownmode = 1
		//bus.write_and_read( load, 2, position, nullptr );

		
		if(y == maxY && value == 1){  
			kolom = 0x00;                       //set next kolom 0x00
		}
	}
}

void ledmatrix::digits(int start, int digit){
	uint8_t leds[3] = {};
	if(digit == 0){
		leds[0] = 0x7C; leds[1] = 0x44;   leds[2] = 0x7C;
	}else if(digit == 1){
		leds[0] = 0x00; leds[1] = 0x00;   leds[2] = 0x7C;
	}else if(digit == 2){
		leds[0] = 0x74; leds[1] = 0x54;   leds[2] = 0x5C;
	}else if(digit == 3){
		leds[0] = 0x54; leds[1] = 0x54;   leds[2] = 0x7C;
	}else if(digit == 4){
		leds[0] = 0x1C; leds[1] = 0x10;   leds[2] = 0x7C;
	}else if(digit == 5){
		leds[0] = 0x5C; leds[1] = 0x54;   leds[2] = 0x74;
	}else if(digit == 6){
		leds[0] = 0x7C; leds[1] = 0x54;   leds[2] = 0x74;
	}else if(digit == 7){
		leds[0] = 0x0C; leds[1] = 0x04;   leds[2] = 0x7C;
	}else if(digit == 8){
		leds[0] = 0x7C; leds[1] = 0x54;   leds[2] = 0x7C;
	}else if(digit == 9){
		leds[0] = 0x5C; leds[1] = 0x54;   leds[2] = 0x7C;
	}
	
	for(int n = 0; n < 3; n++){
		uint8_t position[2] = {};
		position[0] =  0x01 * (start+n+1); position[1] =  leds[n];                 
		bus.write_and_read( load, 2, position, nullptr );
	}
}

void ledmatrix::testmatrix(int ms){
	for(int k = 1; k >= 0; k--){
		for( int j = 0; j <= maxX ; j++){
			for(int i = 0; i <= maxY; i++){
				write_pixel(j,i,k);
				hwlib::wait_ms( ms );
			}
		}
	}
}