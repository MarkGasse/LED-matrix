#include "ledmatrix.hpp"
#include "ostream"

//TESTS setpixel function

bool testX_on(ledmatrix & m , int x){
	m.setpixel(x,1,1);
	if(m.getRows(x) == 1){
		return true;
	}
	return false;

}

bool testX_off(ledmatrix & m , int x){
	m.setpixel(x,1,0);
	if(m.getRows(x) == 0){
		return true;
	}
	return false;

}

bool testY_on(ledmatrix & m , int y){
	uint8_t column = 0x00;
	column |= (1 << (y - 1));
	m.setpixel(2,y,1);
	if(m.getcolumns(y) == column ){
		return true;
	}
	return false;

}

bool testY_off (ledmatrix & m , int y){
	m.setpixel(2,y,0);
	if(m.getcolumns(y) == 0){
		return true;
	}
	return false;

}

int main(void){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
   auto clock = target::pin_out( target::pins::d10 );   //CLK
   auto load = target::pin_out( target::pins::d9 );     //CS
   auto data = target::pin_out( target::pins::d8 );     //DIN
   auto spi_bus = hwlib::spi_bus_bit_banged_sclk_mosi_miso( clock, data, hwlib::pin_in_dummy );
	
    ledmatrix m(8,8,spi_bus,load);
	
	hwlib::cout << "test X on :	" << (int)testX_on(m,7) << hwlib::endl;
	hwlib::cout << "test X off:	" << (int)testX_off(m,9) << hwlib::endl;
	hwlib::cout << "test Y on :	" << (int)testY_on(m,10) << hwlib::endl;
	hwlib::cout << "test Y off:	" << (int)testY_off(m,2) << hwlib::endl;
}