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
	//uint8_t koloms[8];
	//bool rows[8];

public:
	ledmatrix(	int maxX, int maxY, hwlib::spi_bus & bus, hwlib::pin_out & load, uint8_t kolom):
	maxX( maxX ),
	maxY( maxY ),
	bus( bus ),
	load( load ),
	kolom( kolom )
	{setup();}
	
	
	void setpixel(int x, int y, bool state);
	
	void setup();
	void intensity(int brithness);
	void clear_all();
	void write_all(int ms);
	void write_pixel(int x, int y, bool value);
	void testmatrix(int ms);
	
};

#endif //LEDMATRIX_HPP