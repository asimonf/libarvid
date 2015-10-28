/*
Arvid software and hardware is licensed under MIT license:

Copyright (c) 2015 Marek Olejnik

Permission is hereby granted, free of charge, to any person obtaining a copy
of this hardware, software, and associated documentation files (the "Product"),
to deal in the Product without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Product, and to permit persons to whom the Product is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Product.

THE PRODUCT IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE PRODUCT OR THE USE OR OTHER DEALINGS
IN THE PRODUCT.

*/

/* 
Service screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "arvid.h"
#include "libarvid.h"
#include "blitter.h"

extern arvid_private ap;

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned char	 pixel_data[76 * 21];
} arvid_logo = {
76, 21,
{
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xb,0xc,0xf,0xd,0xd,0x0,0x0,0x0,0xc,0xd,0xf,0xf,0xf,0xf,0xf,0xf,0xc,0x9,0x4,0x0,0x0,0x0,0x5,0xc,0xd,0xb,0x4,0xf,0x8,0x0,0x0,0x0,0x4,0xc,0xf,0xd,0xd,0x0,0x0,0x0,0x0,0x7,0xd,0x8,0x5,0xd,0xf,0x2,0x0,0x0,0x2,0xd,0xf,0xf,0xf,0xf,0xf,0xd,0xc,0xb,0x5,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0xf,0x2,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x7,0xf,0xf,0xf,0xb,0xf,0x9,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xd,0x3,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0xf,0x3,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xb,0x0,0x4,0xf,0xf,0xf,0xf,0xf,0x9,0x0,0x0,0x4,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x2,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xb,0xf,0xf,0xf,0xf,0xf,0xf,0x4,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x3,0x3,0xf,0xf,0xf,0xf,0xf,0x9,0x0,0x0,0x9,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x3,0xf,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xc,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x5,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x4,0x0,0x7,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x7,0x0,0xf,0xf,0xf,0xf,0xf,0x9,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0x3,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0xf,0x4,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x5,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0x3,0xb,0xf,0xf,0xb,0xf,0x4,0x7,0xf,0xf,0xf,0xf,0xf,0x8,0x0,0xd,0xf,0xf,0xf,0xf,0xb,0x0,0x3,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0xb,0xf,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0x0,0x3,0x9,0xb,0xf,0xf,0xd,0x3,0x5,0xd,0xf,0xf,0xf,0xf,0xf,0xb,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0xc,0xf,0xf,0xf,0xd,0xd,0x0,0x0,0xb,0xf,0xf,0xf,0xf,0x7,0x0,0xc,0xf,0xf,0xf,0xf,0xb,0x0,0x8,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0xf,0x2,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0x9,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0xd,
0x0,0x0,0x0,0x0,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x9,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0x3,0x0,0x9,0xf,0xf,0xf,0xf,0xc,0x0,0xc,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0x9,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0x0,0x9,0xf,0xf,0xf,0xf,0xf,
0x0,0x0,0x0,0x0,0x0,0x0,0xb,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x7,0x0,0x3,0xf,0xf,0xf,0xf,0xf,0x4,0x0,0x4,0xf,0xf,0xf,0xf,0xc,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xd,0x0,0xf,0xf,0xf,0xf,0x9,0x0,0x0,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0x9,0x0,0x0,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xf,
0x0,0x0,0x0,0x0,0x0,0x3,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x7,0x0,0x5,0xf,0xf,0xf,0xf,0xf,0x3,0x7,0xf,0xf,0xf,0xf,0xf,0x4,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0xd,0x5,0xf,0xf,0xf,0xf,0x3,0x0,0x0,0x0,0x0,0x5,0xf,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x2,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xf,
0x0,0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0x5,0xf,0xf,0xf,0xf,0xf,0x7,0x0,0x8,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x8,0x0,0x0,0x0,0x4,0xf,0xf,0xf,0xf,0xf,0xd,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xf,0x2,0x0,0x0,0x0,0x3,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0xb,0xf,0xf,0xf,0xf,0xc,
0x0,0x0,0x0,0x0,0x4,0xf,0xf,0xf,0xf,0xc,0x0,0xd,0xf,0xf,0xf,0xf,0x7,0x0,0x7,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x8,0x0,0x0,0x0,0x0,0x0,0x9,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0x5,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0x7,
0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0x3,0x0,0xc,0xf,0xf,0xf,0xf,0x5,0x0,0x8,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x2,0x0,0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0x0,0x3,0xf,0xf,0xf,0xf,0xf,0x2,
0x0,0x0,0x0,0x4,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0x5,0x0,0xb,0xf,0xf,0xf,0xf,0x8,0xf,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xc,0x0,0x0,0x0,0x0,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0x0,0x0,0xb,0xf,0xf,0xf,0xf,0x3,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0xb,0x0,
0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x5,0x0,0xc,0xf,0xf,0xf,0xd,0x0,0xc,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x8,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x3,0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0xf,0x2,0x0,
0x0,0x0,0x4,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xc,0xd,0xf,0xf,0xf,0xf,0x4,0x0,0xf,0xf,0xf,0xf,0xb,0x0,0x4,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x5,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xc,0x0,0x0,0x9,0xf,0xf,0xf,0xf,0xf,0x9,0x0,0x0,
0x0,0x0,0xc,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x4,0x0,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,0x0,0x2,0xf,0xf,0xf,0xf,0xc,0x9,0xd,0xf,0xf,0xf,0xf,0xf,0xd,0x0,0x0,0x0,
0x0,0x4,0xf,0xf,0xf,0xf,0xf,0xf,0xd,0xb,0x8,0xd,0xf,0xf,0xf,0xf,0x3,0x2,0xf,0xf,0xf,0xf,0x4,0x0,0x0,0x4,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x0,0x0,0xd,0xf,0xf,0xf,0xf,0xf,0x7,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x0,0x3,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0x2,0x0,0x0,0x0,
0x0,0xc,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0x3,0x4,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0xb,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x5,0xf,0xf,0xf,0xf,0x8,0x0,0x0,0x0,0x0,0x5,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xd,0x2,0x0,0x0,0x0,0x0,
0x3,0xf,0xf,0xf,0xf,0x3,0x0,0x0,0x0,0x0,0x0,0x8,0xf,0xf,0xf,0xf,0x2,0x7,0xf,0xf,0xd,0xb,0x0,0x0,0x0,0x0,0x4,0xf,0xf,0xf,0xf,0x4,0x0,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0xb,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0x5,0x0,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf,0x8,0xf,0xf,0xf,0xf,0x8,0x0,0x0,0x0,0x0,0x0,0x0,
0x5,0xb,0xc,0xc,0x8,0x0,0x0,0x0,0x0,0x0,0x0,0x5,0xf,0xc,0xb,0xb,0x0,0x4,0xd,0xb,0x8,0x5,0x0,0x0,0x0,0x0,0x0,0xc,0xf,0xf,0xf,0x8,0x0,0x0,0x0,0x0,0x2,0xf,0x7,0xf,0xf,0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x5,0xc,0xd,0xc,0x2,0x0,0x0,0x0,0x0,0x5,0xb,0xf,0xd,0x8,0x2,0x9,0x9,0x7,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
}
};



int arvid_show_service_screen(void) {
	unsigned short* fb;
	unsigned short* framePtr;
	int topLine;
	const unsigned short grayBright = COLOR(0x7F, 0x7F, 0x7F);
	const unsigned short grayDark = COLOR(0x3F, 0x3F, 0x3F);
	const unsigned short borderColor = COLOR(0x7F, 0x2F, 0x2f);
	int i, j;
	int posX, posY;
	int rotate;
	unsigned short* image;
	int max;

	//sanity check
	ARVID_INIT_CHECK;
	if (ap.ddrMem == NULL) {
		return ARVID_ERROR_NOT_INITIALIZED;
	}

	fb = ap.fb[0];

	// top line:  3/4 of the empty space 
	topLine = ((ap.lines - ap.fbHeight) / 8) * 6;

	for (j = 0; j < ap.fbHeight; j++) {
		framePtr = &fb[ap.fbWidth * (j + topLine)];
		if ((j & 7) == 0) {
			//solid bright line
			for (i = 0; i < ap.fbWidth; i++) {	
				framePtr[i] = grayBright;
			}
		} else {
			//grid line
			for (i = 0; i < ap.fbWidth; i++) {	
				framePtr[i] = (i & 0x7) == 0 ? grayBright : grayDark;
			}
		}
	}

	//generate RGB shade pattern
	posX = (ap.fbWidth - (32 * 4)) / 2 ;
	posX = (posX >> 3) << 3; //make it 8 pixel boundary
	posY = 56 + topLine;
	for (i = 0; i < 32; i++) {
		arvid_fill_rect(0, posX,      posY + (i * 4), 32, 4, COLOR(i << 3, 0, 0)); // red
		arvid_fill_rect(0, posX + 32, posY + (i * 4), 32, 4, COLOR(0, i << 3, 0)); // green
		arvid_fill_rect(0, posX + 64, posY + (i * 4), 32, 4, COLOR(0, 0, i << 3)); // blue
		arvid_fill_rect(0, posX + 96, posY + (i * 4), 32, 4, (i << 10) | (i << 5) | i); // red
	}

	//higlight borders - top and bottom
	j = ap.fbWidth / 8;
	for (i = 0; i < j; i++) {
		arvid_fill_rect(0, 3 + i * 8, topLine + 3, 3, 3, borderColor);
		arvid_fill_rect(0, 3 + i * 8, topLine + ap.fbHeight - 5, 3, 3, borderColor);
	}


	//higlight borders - left and right
	j = ap.fbHeight / 8;
	for (i = 0; i < j; i++) {
		arvid_fill_rect(0, 3, topLine + 3 + i * 8, 3, 3, borderColor);
		arvid_fill_rect(0, ap.fbWidth - 5, topLine + 3 + i * 8, 3, 3, borderColor);
	}

	//convert logo to unsigned short format
	max = arvid_logo.width * arvid_logo.height;
	image = (unsigned short*) malloc(max * 2);
	for (i = 0; i < max; i++) {
		unsigned short c = arvid_logo.pixel_data[i] << 4;
		if (c) {
			image[i] = (unsigned short) COLOR(c,c,c);
		} else {
			image[i] = grayDark;
		}
	}


	//check tate switch
	rotate = arvid_get_button_state() & ARVID_TATE_SWITCH;

	//draw logo background
	if (rotate) {
		posX = ap.fbWidth - arvid_logo.height + 1;
		posX -= ap.fbWidth > 256 ? 30 : 22;
		posY = (ap.fbHeight - arvid_logo.width) / 2 + topLine;
		arvid_fill_rect(0, posX - 4, posY - 4, arvid_logo.height + 8, arvid_logo.width + 8, grayDark);
	} else {
		posX = (ap.fbWidth - arvid_logo.width) / 2;
		posY = 22 + topLine;
		arvid_fill_rect(0, posX - 4, posY - 4, arvid_logo.width + 8, arvid_logo.height + 8, grayDark);
	}
	//draw logo
	arvid_draw_image(0, posX, posY, arvid_logo.width, arvid_logo.height, image, rotate);

	free(image);

	//copy framebuffer
	memcpy(ap.fb[1], ap.fb[0], 0x100000);
	return 0;
}