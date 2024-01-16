/*
 * ILI9341_test.h
 *
 *  Created on: Jan 2, 2024
 *      Author: OSES-Group
 */

#ifndef INC_ILI9341_TEST_H_
#define INC_ILI9341_TEST_H_

#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))


#define BGCOLOR BLACK

void Displ_PerfTest();
void Displ_ColorTest();
void Displ_TestAll ();

#endif /* INC_ILI9341_TEST_H_ */
