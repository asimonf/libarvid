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

#ifndef _LIBARVID_H_
#define _LIBARVID_H_



//internal for arvid
#define INITIAL_VIDEO_MODE arvid_320
#define INITIAL_VIDEO_MODE_INDEX 0
#define INITIAL_FB_W  320
#define INITIAL_FB_H  224
//#define INITIAL_FB_LINES 304
#define INITIAL_FB_LINES 253


#define RATE_SIZE 57

#define ARVID_INIT_CHECK if (ap.initialized != 0xACCE5503) return ARVID_ERROR_NOT_INITIALIZED

#define COLOR(r,g,b) (((r) >> 3) << 10) | (((g) >> 3) << 5) | ((b) >> 3)

//PRU Data:
//byte 0  - 63 : header: video mode registers and misc info (16 integers)
//byte 64 - XX : frame buffer data - individal pixels of a single line
//               in ARGB1555 format streamed from DDR

//Frame buffer address index
#define PRU_DATA_FB_ADDR 0

//Frame sequential number
#define PRU_DATA_FRAME_NUMBER 1

//line length block count
#define PRU_DATA_BLOCK_COUNT 2

//number of lines to render
#define PRU_DATA_TOTAL_LINES 3

//gpio state - buttons
#define PRU_DATA_GPIO_STATE 4

//X position of the first pixel - allows to shift screen horizontally
#define PRU_DATA_LINE_POS_MOD 5

//currently rendered line
#define PRU_DATA_LINE_NUMBER 6

//Pass universal timing data
#define PRU_DATA_UNIVERSAL_TIMINGS 7
//Enable interlaced mode
#define PRU_DATA_INTERLACING_ENABLED 9

typedef struct arvid_private_t {
	unsigned int initialized;
	unsigned int ddrAddress;
	unsigned int* ddrMem;
	volatile unsigned int* pruMem;
	volatile unsigned int* pruSharedMem;
	int ddrFd;
	int linePosMod;
	int interlacing;

	int lines;
	int fbWidth;
	int fbHeight;
	unsigned short* fb[2];
	volatile unsigned int vsyncCnt;
	int vsyncLine;
	//for screen saver
	unsigned int activity;
	unsigned int lastActivity;
	unsigned int burnCounter;
	arvid_service_screen_func serviceScreen;
} arvid_private;

typedef struct arvid_line_rate_t {
	unsigned short line;
	float rate;
} arvid_line_rate;

typedef struct arvid_mode_cycle_data_t {
	unsigned short pixels_per_line;
	unsigned short asymetric_pixels;
	
	unsigned char passive_cycles_per_pixel;
	unsigned char passive_cycles_per_pixel_mod;
	
	unsigned char line_end_delay;
	unsigned char line_end_delay_mod;
	
} arvid_mode_cycles;

unsigned int arvid_get_vsync_number(void);
int arvid_get_virtual_vsync(void);

#endif