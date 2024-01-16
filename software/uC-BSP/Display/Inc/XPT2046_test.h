/*
 * XPT2046_test.h
 *
 *  Created on: Jan 2, 2024
 *      Author: OSES-Group
 */

#ifndef INC_XPT2046_TEST_H_
#define INC_XPT2046_TEST_H_

#include <stdlib.h>

#define NUM_READINGS	40

void Touch_ShowData(void);
void Touch_TestCalibration(void);
void DrawCross(uint16_t x,uint16_t y,uint16_t fcol);
void Touch_TestDrawing();

#endif /* INC_XPT2046_TEST_H_ */
