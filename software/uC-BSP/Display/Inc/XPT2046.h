/*
 * XPT2046.h
 *
 *  Created on: Jan 2, 2024
 *      Author: OSES-Group
 */

#ifndef INC_XPT2046_H_
#define INC_XPT2046_H_

#define TOUCH_SPI_PORT 	hspi2
#define TOUCH_SPI 		SPI2

#define DELAY_TO_KEY_REPEAT -1

#define X_AXIS		0xD0
#define Y_AXIS		0x90
#define Z_AXIS		0xB0

#ifdef ILI9341
#define X_THRESHOLD		0x0200	//below threeshold there is no touch
#define Z_THRESHOLD		0x0200	//below threeshold there is no touch
#endif

#ifdef ILI9341
#define T_ROTATION_0
#define AX 0.008295f
#define BX -19.376f
#define AY 0.010239f
#define BY -33.797f
#endif

#ifdef T_ROTATION_0
#define TOUCH0 			Displ_Orientat_0
#define TOUCH90 		Displ_Orientat_90
#define TOUCH180 		Displ_Orientat_180
#define TOUCH270 		Displ_Orientat_270
#define TOUCH_0_WIDTH 	DISPL_WIDTH
#define TOUCH_0_HEIGHT	DISPL_HEIGHT
#endif

#ifdef T_ROTATION_90
#define TOUCH0 			Displ_Orientat_90
#define TOUCH90 		Displ_Orientat_180
#define TOUCH180 		Displ_Orientat_270
#define TOUCH270 		Displ_Orientat_0
#define TOUCH_0_WIDTH 	DISPL_HEIGHT
#define TOUCH_0_HEIGHT	DISPL_WIDTH
#endif

#ifdef T_ROTATION_180
#define TOUCH0 			Displ_Orientat_180
#define TOUCH90 		Displ_Orientat_270
#define TOUCH180 		Displ_Orientat_0
#define TOUCH270 		Displ_Orientat_90
#define TOUCH_0_WIDTH 	DISPL_WIDTH
#define TOUCH_0_HEIGHT	DISPL_HEIGHT
#endif

#ifdef T_ROTATION_270
#define TOUCH0 			Displ_Orientat_270
#define TOUCH90 		Displ_Orientat_0
#define TOUCH180 		Displ_Orientat_90
#define TOUCH270 		Displ_Orientat_180
#define TOUCH_0_WIDTH 	DISPL_HEIGHT
#define TOUCH_0_HEIGHT	DISPL_WIDTH
#endif

//touch gxf possible implemets

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

uint8_t Touch_In_XY_area(uint16_t xpos,uint16_t ypos,uint16_t width,uint16_t height);
uint8_t Touch_GotATouch(uint8_t reset);
uint8_t Touch_WaitForUntouch(uint16_t delay);
uint8_t Touch_WaitForTouch(uint16_t delay);
uint8_t Touch_PollTouch();
void Touch_GetXYtouch(uint16_t *x, uint16_t *y, uint8_t *isTouch);

#endif
