/** \file
 * Save your Arduino sketch to the Arduino firmware.
 *
 * This requires that you have a way to call the sketch_output
 * function and a way to extract the tar file on the computer.
 *
 * TODO: Write a howto demonstrating this function.
 */

/*
 * Generate a tar file of the source code;
tar \
	-jcvf - \
	--exclude source_raw.h \
	--exclude '.git*' \
	--exclude '.hg*' \
	--exclude '.*.swp' \
	-C .. \
	"./$(basename $(pwd))" \
| xxd -i > source_raw.h
*/

#include <Arduino.h>
#include "SketchSaver.h"

#include <avr/pgmspace.h>
static const uint8_t source[] PROGMEM = {
#include "source_raw.h"
};

static void hex_print(uint32_t x, unsigned digits)
{
	for(unsigned i = 0 ; i < digits ; i++)
	{
		Serial.print((x >> (4 * (digits - i - 1))) & 0xF, HEX);
	}
}


void sketch_output()
{
	for(size_t i = 0 ; i < sizeof(source) ; i++)
	{
		if((i % 16 == 0))
		{
			Serial.println();
			hex_print(i, 6);
		}
		Serial.print(" ");
		hex_print(pgm_read_byte_near(&source[i]), 2);
	}
	Serial.println();
}

