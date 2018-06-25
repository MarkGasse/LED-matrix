#ifndef LEDMATRIX_HPP
#define LEDMATRIX_HPP

#include "hwlib.hpp"
/// @file

/// \brief
///
/// \details
///
class ledmatrix {
private:
	int maxX;
	int maxY;
	hwlib::spi_bus & bus;
	hwlib::pin_out & load;
	uint8_t kolom = 0x00;
	uint8_t koloms[8];
	bool rows[8];

public:

	/// \brief
	///
	/// \details
	///
	ledmatrix(	int maxX, int maxY, hwlib::spi_bus & bus, hwlib::pin_out & load):
	maxX( maxX ),
	maxY( maxY ),
	bus( bus ),
	load( load )
	{
		setup();
		for(int i = 0; i < 8; i++){
			koloms[i] = 0x00;
		}
		for(int j = 0; j < 8; j++){
			rows[j] = 0;
		}
	}

	/// \brief
	///
	/// \details
	///
	void setup();
	
	/// \brief
	///
	/// \details
	///
	void setpixel(int x, int y, bool state);

	/// \brief
	///
	/// \details
	///
	void writepixels();

	/// \brief
	///
	/// \details
	///
	void intensity(int brithness);

	/// \brief
	///
	/// \details
	///
	void clear_all();

	/// \brief
	///
	/// \details
	///
	void write_all(int ms);

	/// \brief
	///
	/// \details
	///
	void write_pixel(int x, int y, bool value);

	/// \brief
	///
	/// \details
	///
	void testmatrix(int ms);
	
};

#endif //LEDMATRIX_HPP