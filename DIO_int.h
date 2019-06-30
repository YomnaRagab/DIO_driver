/*
 * DIO_int.h
 *
 *  Created on: Sep 27, 2018
 *      Author: Dell
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "..\LIB\types.h"
#define INPUT 0
#define OUTPUT 1
#define LOW 0
#define HIGH 1
#define A 0
#define B 1
#define C 2
#define D 3
extern void DIO_VidGetPinDirection (u8 pinNumber,u8 direction);
extern void DIO_VidSetPinValue (u8 pinNumber,u8 value);
extern u8 DIO_u8GetPinValue (u8 pinNumber);
extern void DIO_VidGetPortDirection (u8 port,u8 direction);
extern void DIO_VidSetPortValue (u8 port,u8 value);
extern void DIO_VidInitialize (void);
#endif /* DIO_INT_H_ */
