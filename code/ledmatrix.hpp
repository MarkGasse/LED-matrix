// ==========================================================================
//
// File      : ledmatrix.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : mark.gasse@student.hu.nl 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

#ifndef LEDMATRIX_HPP
#define LEDMATRIX_HPP

#include "hwlib.hpp"
/// @file

/// \brief
///	2D ledmatrix library
/// \details
///	This is a library for controlling a ledmatrix.
/// The maxX and maxY are stored as two (signed) integers.
/// The bus exists of the data and clock output.
/// Load (CS) for loading the data on the matrix.
/// Koloms is an array of uint8_t to store the byte values.
/// Rows is an array of booleans to store the row values.
class ledmatrix {
protected:
	int maxX;
	int maxY;
	hwlib::spi_bus & bus;
	hwlib::pin_out & load;
	uint8_t kolom = 0x00;
	uint8_t koloms[8];
	bool rows[8];

public:

	/// \brief
	///	default contructor
	/// \details
	///	This constructor does not initialize the koloms and rows.
	/// The constructor sets the default value's for the two arrays and the setup function.
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
	///	Setting default value's
	/// \details
	/// This function sets the brigthness, size and mode of the matrix.
	void setup();
	
	/// \brief
	///	write position to array
	/// \details
	/// This function writes the y position to the array koloms
	/// and the x position to the array rows.
	void setpixel(int x, int y, bool state);

	/// \brief
	///	write to ledmatrix display
	/// \details
	/// This function loops over the koloms and rows arrays and
	/// writes all leds on the display.
	void writepixels();

	/// \brief
	///	set brigthness of leds
	/// \details
	///	This function sets the intensity of the leds.
	void intensity(int brithness);

	/// \brief
	/// clears all leds
	/// \details
	/// This function sets a 0 for every row and kolom.
	void clear_all();

	/// \brief
	/// write all leds
	/// \details
	/// This function sets every a 1 for every row and kolom.
	/// The speed of setting the leds depends on the ms value.
	void write_all(int ms);

	/// \brief
	/// write position
	/// \details
	/// This function turns a led on or off based on the state,
	/// and writes this on the x and y coordinates.
	/// If you are using loops: the setpixel and writepixels functions are recommended.
	void write_pixel(int x, int y, bool value);

	/// \brief
	/// write digit
	/// \details
	/// This function needs a start position (x) and a digit.
	/// It will write this digit on the display starting at the x position.
	void digits(int start, int digit);
	
	/// \brief
	/// counter
	/// \details
	/// This function is een counter from 0 to a maximum of 99,
	/// the fistmax is the maximum digit for 00,10,20,30....90 and
	/// the secondmax is the maximum digit for 00,01,02.....09.
	/// The speed of the counter depends on the ms value
	void counter(int firstmax, int secondmax ,int ms);
	
	/// \brief
	/// get koloms
	/// \details 
	/// This function gets the byte in the array on position and checks if the position is in range.
	/// If position is in range the byte on that position will be returnt and 
	/// if position is not in range -1 will be returnt
	uint8_t getKoloms(int position);
	
	/// \brief
	/// get rows
	/// \details 
	/// This function gets the bool in the array on position and checks if the position is in range.
	/// If position is in range the bool on that position will be returnt and 
	/// if position is not in range -1 will be returnt
	bool getRows(int position);
};

#endif //LEDMATRIX_HPP