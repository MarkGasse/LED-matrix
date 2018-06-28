#include "ledmatrix.hpp"
#include "ostream"
//using namespace std;

bool setpixelonx(ledmatrix & m , int x){
	m.setpixel(x,1,1);
	if(m.getRows(x) == 1){
		return true;
	}
	return false;

}

bool setpixelofx(ledmatrix & m , int x){
	m.setpixel(x,2,0);
	if(m.getRows(x) == 0){
		return true;
	}
	return false;

}

bool setpixelony(ledmatrix & m , int y){
	uint8_t kolom = 0x00;
	kolom |= (1 << (y - 1));
	m.setpixel(1,y,1);
	if(m.getKoloms(y) == kolom ){
		return true;
	}
	return false;

}

bool setpixelofy(ledmatrix & m , int y){
	m.setpixel(4,y,0);
	if(m.getKoloms(y) == 0){
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
	hwlib::cout << "test 1:" << setpixelonx(m,2) << hwlib::endl;
	hwlib::cout << "test 2:" << setpixelofx(m,3) << hwlib::endl;
	hwlib::cout << "test 3:" << setpixelony(m,2) << hwlib::endl;
	hwlib::cout << "test 4:" << setpixelofy(m,8) << hwlib::endl;
   
}