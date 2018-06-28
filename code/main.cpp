#include "ostream" 
#include "ledmatrix.hpp"
#include "snake.hpp"
#include "fruit.hpp"
using namespace std;

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
   auto clock = target::pin_out( target::pins::d10 );   //CLK
   auto load = target::pin_out( target::pins::d9 );     //CS
   auto data = target::pin_out( target::pins::d8 );     //DIN
   auto spi_bus = hwlib::spi_bus_bit_banged_sclk_mosi_miso( clock, data, hwlib::pin_in_dummy );
   
   auto left = target::pin_in( target::pins::d7);
   auto down = target::pin_in( target::pins::d6);
   auto right = target::pin_in( target::pins::d5);
   auto up = target::pin_in( target::pins::d4);

   int direction = 1;
   int tailSize = 1;
   ledmatrix m(8,8,spi_bus,load);
   fruit f(m,8,8,6,6);
   snake s(m,f,direction,tailSize);
	
   for(;;){
		// snake game speed
		hwlib::wait_ms( 150 );
		
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
		
		s.update(direction);
		s.draw(1);
		f.draw(1);
		m.writepixels();
		s.draw(0);
		f.draw(0);
		s.checkFruit();
   }
}
