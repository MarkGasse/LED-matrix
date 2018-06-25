#ifndef LEDMATRIX_HPP
#define LEDMATRIX_HPP

#include "hwlib.hpp"

class ledmatrix {
private:
	int maxX;
	int maxY;
	hwlib::spi_bus & bus;
	hwlib::pin_out & load;
	uint8_t kolom;
	uint8_t koloms[8];
	bool rows[8];

public:
	ledmatrix(	int maxX, int maxY, hwlib::spi_bus & bus, hwlib::pin_out & load, uint8_t kolom):
	maxX( maxX ),
	maxY( maxY ),
	bus( bus ),
	load( load ),
	kolom( kolom )
	{
		setup();
		for(int i = 0; i < 8; i++){
			koloms[i] = 0x00;
		}
		for(int j = 0; j < 8; j++){
			rows[j] = 0;
		}
	}
	
	
	void setpixel(int x, int y, bool state);
	void testscreen();
	void setup();
	void intensity(int brithness);
	void clear_all();
	void write_all(int ms);
	void write_pixel(int x, int y, bool value);
	void testmatrix(int ms);
	
};

#endif //LEDMATRIX_HPP