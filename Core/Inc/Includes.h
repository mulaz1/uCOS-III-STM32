/*********************************************************************************************************
 *                                              uC/OS-III
 *                                        The Real-Time Kernel
 *
 *                          (c) Copyright 2004-2012; Micrium, Inc.; Weston, FL
 *
 *               All rights reserved.  Protected by international copyright laws.
 *
 *               uC/OS-III is provided in source form for FREE evaluation, for educational
 *               use or peaceful research.  If you plan on using uC/OS-III in a commercial
 *               product you need to contact Micrium to properly license its use in your
 *               product.  We provide ALL the source code for your convenience and to
 *               help you experience uC/OS-III.  The fact that the source code is provided
 *               does NOT mean that you can use it without paying a licensing fee.
 *
 *               Knowledge of the source code may NOT be used to develop a similar product.
 *
 *               Please help us continue to provide the Embedded community with the finest
 *               software available.  Your honesty is greatly appreciated.
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *
 *                                           MASTER INCLUDES
 *
 *                                             NXP LPC1768
 *                                                on the
 *                                     IAR LPC1768-SK Kickstart Kit
 *
 * Filename      : includes.h
 * Version       : V1.00
 * Programmer(s) : FT
 *********************************************************************************************************
 */
#ifndef  __INCLUDES_H
#define  __INCLUDES_H

/*
 *********************************************************************************************************
 *                                         STANDARD LIBRARIES
 *********************************************************************************************************
 */

#include  <stdarg.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>

/*
 *********************************************************************************************************
 *                                              LIBRARIES
 *********************************************************************************************************
 */

#include  "uC-CPU/ARM-Cortex-M4/GNU/cpu.h"
#include  "uC-LIB/lib_def.h"
#include  "uC-LIB/lib_ascii.h"
#include  "uC-LIB/lib_math.h"
#include  "uC-LIB/lib_mem.h"
#include  "uC-LIB/lib_str.h"

/*
 *********************************************************************************************************
 *                                              APP / BSP
 *********************************************************************************************************
 */

//#include  "user/configuration_os/inc/app_cfg.h"

//BOARD FILES

/*
 *********************************************************************************************************
 *                                                 OS
 *********************************************************************************************************
 */

#include  "uCOS-III/Source/os.h"

/*
 *********************************************************************************************************
 *                                            INCLUDES END
 *********************************************************************************************************
 */

#endif
