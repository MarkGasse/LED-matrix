#include "ostream" 
#include "ledmatrix.hpp"
#include "vector"
#include "string"
using namespace std;

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
  
   auto left = target::pin_in( target::pins::d5);
   auto right = target::pin_in( target::pins::d4);
   auto up = target::pin_in( target::pins::d7);
   auto down = target::pin_in( target::pins::d6);

   auto clock = target::pin_out( target::pins::d10 );   //CLK
   auto load = target::pin_out( target::pins::d9 );     //CS
   auto data = target::pin_out( target::pins::d8 );     //DIN
   auto spi_bus = hwlib::spi_bus_bit_banged_sclk_mosi_miso( clock, data, hwlib::pin_in_dummy );

   ledmatrix m(8,8,spi_bus,load,0x00);
	//m.setup();

		//vector<int> testA[] = {};
		//testA[0] = {int x = 1, int y = 1};

	   // start position fruit
	   int fx = 6; int fy = 6;
	   // start position snake
	   //vector<int> snake[] = {};
	  // int sx = snake[0][0] = 1; int sy = snake[0][1] = 1;
	   
	   
	   
	   
	   
	   
	   int snakeX[64] = {};
	   int snakeY[64] = {};
	   snakeX[0] = 1;
	   snakeY[0] = 1;
	   
	   int tailSize = 1;
	   
	   
	   
		//int sxx = sx; int syy = sy;
	   int direction = 1;
	   int mode = 1;
	   //int snakeSize = 1;
	   //int value;
	   while(mode == 1){
		   //set time for while loop to 0
		   int wait_time = 0;
		   //generate random fruit position 
		   int z = rand() % 7 + 1;
		   // last tail position x and y
		   int tailEndX = snakeX[0]; 
		   int tailEndY = snakeY[0];
		   //int x, y;
		   for(int k = 0; k < tailSize; k++){
			   int tmpx = snakeX[k]; 
			   int tmpy = snakeY[k];
			   snakeX[k] = tailEndX; 
			   snakeY[k] = tailEndY;
			   tailEndX = tmpx; 
			   tailEndY = tmpy;
		   }
		   
		   
		   // setting snake direction 
			if(right.get() == 0 && direction != 2){
				 	direction = 1;
			}else if(left.get() == 0 && direction != 1){
					direction = 2;
			}else if(up.get() == 0 && direction != 4){
					direction = 3;
			}else if(down.get() == 0 && direction != 3){
				 	direction = 4;
			}

			// moving the snake every update
			if(direction == 1){snakeX[0] += 1;}
			if(direction == 2){snakeX[0] -= 1;}
			if(direction == 3){snakeY[0] += 1;}
			if(direction == 4){snakeY[0] -= 1;}
			
			// looping for sometime before next update
			for(int l = 0; l < (70/tailSize); l++){
				
				
				// writing snakes position
				for(int i = 0; i < tailSize; i++){
					m.write_pixel(snakeX[i],snakeY[i],1);
					m.write_pixel(snakeX[i],snakeY[i],0);
				}
				
				// giving fruit the new position
				if(snakeX[0] == fx && snakeY[0] ==fy){
					fx = z; fy = z;
					tailSize++;
					//value = 1;
				}//else{
				//	value = 0;
				//}
				//m.write_pixel(sx,sy,0);
				
				
				// writing fruits position
				m.write_pixel(fx,fy,1);
				m.write_pixel(fx,fy,0);
				
				// game over 
				if(snakeX[0] == 9 || snakeX[0] == 0 || snakeY[0] == 9 || snakeY[0] == 0){
					mode = 0;
				}
				wait_time++;
			}
	   }
	m.clear_all();
	m.intensity(2);
	m.write_all(20);
   
}