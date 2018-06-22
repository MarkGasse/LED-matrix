#include "ledmatrix.hpp"


void ledmatrix::setpixel(int x, int y, bool state){
	//
	//uint8_t koloms[8] = {};
	// rows you need to write 1 and rows you can skip 0
	//bool rows[8] = {};
	/*for(int b = 0; b < 8; b++){
		if(rows[b] == 0){
			koloms[b] = 0x00;
		}
	}
	
	
	if(state == 1){
		rows[x] = 1;
		koloms[x] |= (1 << (y - 1));
	}else{
		rows[x] = 0;
		koloms[x] &= ~(1 << (y - 1));
	}*/
}












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

void ledmatrix::intensity(int brithness){
	// set intensity  
	uint8_t position [2] = {};
	uint8_t bn = 0x01 * brithness;
	position[0] =  0x0A; position[1] =  bn ;               
	bus.write_and_read( load, 2, position, nullptr );
}

void ledmatrix::clear_all(){
	//turn all leds off	
	for( int j = 1; j <= maxX ; j++){
		for(int i = 0; i <= maxY; i++){
			write_pixel(j,i,0);
		}
	}
}

void ledmatrix::write_all(int ms){
	//turn all leds on
	for( int j = 1; j <= maxX ; j++){
		for(int i = 0; i <= maxY; i++){
			write_pixel(j,i,1);
			hwlib::wait_ms( ms );
		}
	}
}

void ledmatrix::write_pixel(int  x, int  y, bool value){
	// array<array<uint8_t,8>,8>
	// [0][0] = 1    [0][1] = 1
	//int array<array<uint8_t,8>,8>;
	/*
	if(x <= maxX && y <= maxY){
		uint8_t position [2] = {};
		for(int a = 0; a < 8; a++){
			if(rows[a] == 1){
				//position[0] =  rows[x]; position[1] =  koloms[y] ;         // position y  
				position[0] =  0x02; position[1] =  0x02; 
				bus.write_and_read( load, 2, position, nullptr );
			}
		}
		position[0] =  0x0C; position[1] =  0x01 ;         // shutdownmode = 1
		bus.write_and_read( load, 2, position, nullptr );
		*/
		
		
		uint8_t position [2] = {};
		uint8_t row = 0x01 * x;
		
		if(value == 1){
			kolom |= (1 << (y - 1));
		}else{
			kolom &= ~(1 << (y - 1));
		}
		
		position[0] =  row; position[1] =  kolom ;         // position y         
		bus.write_and_read( load, 2, position, nullptr );

		position[0] =  0x0C; position[1] =  0x01 ;         // shutdownmode = 1
		bus.write_and_read( load, 2, position, nullptr );

		
		if(y == maxY && value == 1){  
			kolom = 0x00;                       //set next kolom 0x00
		}
		
		
		/*
		if(y == maxY && value == 0){
			kolom = 0x00;
			for(int h = 0; h < y; h++){
				kolom |= (1 << h);
			}
		}*/
	//}
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
