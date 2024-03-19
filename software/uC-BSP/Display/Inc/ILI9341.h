/*
 * ILI9341.h
 *
 *  Created on: Jan 2, 2024
 *      Author: OSES-Group
 */

#ifndef INC_ILI9341_H_
#define INC_ILI9341_H_

#define ILI9341
#define DISPL_SPI_PORT 	hspi1
#define DISPL_SPI 		SPI1
#define DISPL_PRESCALER SPI_BAUDRATEPRESCALER_2
#define TOUCH_PRESCALER SPI_BAUDRATEPRESCALER_2
#define DISPLAY_SPI_DMA_MODE
#define BUFLEVEL 8

#ifdef ILI9341
#define Z_RGB565
#endif

#ifdef ILI9341
#define DISPL_WIDTH  240
#define DISPL_HEIGHT 320
#endif

#define DISPL_DMA_CUTOFF 	20

#include <string.h>

typedef enum {
	Displ_Orientat_0,
	Displ_Orientat_90,
	Displ_Orientat_180,
	Displ_Orientat_270
} Displ_Orientat_e;

#define SPI_COMMAND 	GPIO_PIN_RESET
#define SPI_DATA 		GPIO_PIN_SET
#define SIZEBUF (1<<BUFLEVEL)

#define	RED			0xF800
#define	GREEN		0x07E0
#define	BLUE		0x001F
#define YELLOW		0xFFE0
#define MAGENTA		0xF81F
#define ORANGE		0xFD00
#define CYAN		0x07FF
#define	D_RED 		0xC000
#define	D_GREEN		0x0600
#define	D_BLUE		0x0018
#define D_YELLOW	0xC600
#define D_MAGENTA	0xC018
#define D_ORANGE	0xC300
#define D_CYAN		0x0618
#define	DD_RED		0x8000
#define	DD_GREEN	0x0400
#define DD_BLUE		0x0010
#define DD_YELLOW	0x8400
#define DD_MAGENTA	0x8020
#define DD_ORANGE	0x8200
#define DD_CYAN		0x0410
#define WHITE		0xFFFF
#define D_WHITE		0xC618
#define DD_WHITE	0x8410
#define DDD_WHITE	0x4208
#define DDDD_WHITE	0x2104
#define	BLACK		0x0000
#define color565(r, g, b) ((((r) & 0xF8) << 8) | (((g) & 0xFC) << 3) | (((b) & 0xF8) >> 3))

#define ILI9341_SLEEP_OUT			0x11
#define ILI9341_DISPLAY_ON			0x29
#define ILI9341_PIXEL_FORMAT    	0x3A
#define ILI9341_RGB_INTERFACE   	0xB0
#define ILI9341_MEMWR				0x2C
#define ILI9341_COLUMN_ADDR			0x2A
#define ILI9341_PAGE_ADDR			0x2B
#define ILI9341_MADCTL				0x36
#define ILI9341_MADCTL_0DEG 		0X88
#define ILI9341_MADCTL_90DEG 		0xE8
#define ILI9341_MADCTL_180DEG 		0x48
#define ILI9341_MADCTL_270DEG 		0x28
#define ILI9341_INIT_SHORT_DELAY	5
#define ILI9341_INIT_LONG_DELAY		150

#define ILI9341_POWER0				0xC0
#define ILI9341_POWER1				0xC1
#define ILI9341_POWERA				0xCB
#define ILI9341_POWERB				0xCF

#define SET_DISPL_SPI_BAUDRATE			DISPL_SPI->CR1 &= (uint16_t) ~SPI_CR1_BR_Msk; \
										DISPL_SPI->CR1 |= DISPL_PRESCALER

#define SET_TOUCH_SPI_BAUDRATE			TOUCH_SPI->CR1 &= (uint16_t) ~SPI_CR1_BR_Msk; \
										TOUCH_SPI->CR1 |= TOUCH_PRESCALER

#define _swap_int16_t(a, b)  { int16_t t = a; a = b; b = t; }

// TODO: works only drawCicle more or less
#ifndef DISPLAY_USING_TOUCHGFX
_Bool Displ_drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void Displ_fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

void Displ_fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void Displ_drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);

void Displ_Border(int16_t x, int16_t y, int16_t w, int16_t h, int16_t t,  uint16_t color);
void Displ_CLS(uint16_t bgcolor);
void Displ_CString(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, const char* str, sFONT font, uint8_t size, uint16_t color, uint16_t bgcolor);
void Displ_fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void Displ_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void Displ_Line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void Displ_FillArea(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void Displ_Orientation(Displ_Orientat_e orientation);
void Displ_Pixel(uint16_t x, uint16_t y, uint16_t color);
void Displ_WChar(uint16_t x, uint16_t y, char ch, sFONT font, uint8_t size, uint16_t color, uint16_t bgcolor);
void Displ_WString(uint16_t x, uint16_t y, const char* str, sFONT font, uint8_t size, uint16_t color, uint16_t bgcolor);
#endif /* ! DISPLAY_USING_TOUCHGFX */

void Displ_FillArea(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void Displ_Orientation(Displ_Orientat_e orientation);
void Displ_Init(Displ_Orientat_e orientation);


//TODO: Just decleareted for definition with interrupt but don't work
//void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);
//void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);

uint32_t  Displ_BackLight(uint8_t cmd);


//da rivedere

#ifdef DISPLAY_USING_TOUCHGFX
int touchgfxDisplayDriverTransmitActive();
void touchgfxDisplayDriverTransmitBlock(const uint8_t* pixels, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
extern void DisplayDriver_TransferCompleteCallback();
extern void touchgfxSignalVSync(void);
#endif /* DISPLAY_USING_TOUCHGFX */



#endif /* INC_ILI9341_H_ */
