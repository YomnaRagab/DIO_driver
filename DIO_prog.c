/*
 * DIO_prog.c
 *
 *  Created on: Sep 27, 2018
 *      Author: Dell
 */
#include "DIO_int.h"
#include "..\LIB\types.h"
#include "..\LIB\math.h"
void DIO_VidGetPinDirection (u8 pinNumber,u8 direction)
{
  if ((pinNumber > 31 ) || (pinNumber < 0))
  {
    // do nothing
  }
  else
  {
    u8 PORT=pinNumber/8;
    u8 PINPORT=pinNumber%8;
    if (direction==INPUT)
    {
      switch (PORT)
        {
          case A:
            CLR(DDRA,PINPORT);
            break;
          case B:
            CLR(DDRB,PINPORT);
            break;
          case C:
            CLR(DDRC,PINPORT);
            break;
          case D:
            CLR(DDRD,PINPORT);
            break;
        }
  }
   else
   {
     switch (PORT)
       {
         case A:
           SET(DDRA,PINPORT);
           break;
         case B:
           SET(DDRB,PINPORT);
           break;
         case C:
           SET(DDRC,PINPORT);
           break;
         case D:
           SET(DDRD,PINPORT);
           break;
       }
   }
}
}
void DIO_VidSetPinValue (u8 pinNumber,u8 value)
{
  if ((pinNumber > 31 ) || (pinNumber < 0))
  {
    // do nothing
  }
  else
  {
    u8 PORT=pinNumber/8;
    u8 PINPORT=pinNumber%8;
    if (value==LOW)
        {
          switch (PORT)
            {
              case A:
                CLR(PORTA,PINPORT);
                break;
              case B:
                CLR(PORTB,PINPORT);
                break;
              case C:
                CLR(PORTC,PINPORT);
                break;
              case D:
                CLR(PORTD,PINPORT);
                break;
            }
      }
       else
       {
         switch (PORT)
           {
             case A:
               SET(PORTA,PINPORT);
               break;
             case B:
               SET(PORTB,PINPORT);
               break;
             case C:
               SET(PORTC,PINPORT);
               break;
             case D:
               SET(PORTD,PINPORT);
               break;
           }
       }

  }
}

u8 DIO_u8GetPinValue (u8 pinNumber)
{
  u8 u8PinValue;
  if ((pinNumber > 31 ) || (pinNumber < 0))
  {
    u8PinValue=0xff;
  }
  else
  {
    u8 PORT=pinNumber/8;
    u8 PINPORT=pinNumber%8;
          switch (PORT)
            {
              case A:
                u8PinValue=GET(PORTA,PINPORT);
                break;
              case B:
                u8PinValue=GET(PORTB,PINPORT);
                break;
              case C:
                u8PinValue=GET(PORTC,PINPORT);
                break;
              case D:
                u8PinValue=GET(PORTD,PINPORT);
                break;
            }
  }
  return(u8PinValue);
}
void DIO_VidGetPortDirection (u8 port,u8 direction)
{
  if  (port <= D)
  {
  if(direction==INPUT)
    {
      switch(port)
    {
      case A:
        CLRPORT(DDRA);
        break;
      case B:
        CLRPORT(DDRB);
        break;
      case C:
        CLRPORT(DDRC);
        break;
      case D:
        CLRPORT(DDRD);
        break;
    }
  }
  else
  {
    switch(port)
      {
        case A:
          SETPORT(DDRA);
          break;
        case B:
          SETPORT(DDRB);
          break;
        case C:
          SETPORT(DDRC);
          break;
        case D:
          SETPORT(DDRD);
          break;
      }
  }
}
  else
  {
    // do nothing
  }
}
void DIO_VidSetPortValue (u8 port,u8 value)
{
  if  (port <= D)
  {
  if(value==LOW)
    {
      switch(port)
    {
      case A:
        CLRPORT(PORTA);
        break;
      case B:
        CLRPORT(PORTB);
        break;
      case C:
        CLRPORT(PORTC);
        break;
      case D:
        CLRPORT(PORTD);
        break;
    }
  }
  else
  {
    switch(port)
      {
        case A:
          SETPORT(PORTA);
          break;
        case B:
          SETPORT(PORTB);
          break;
        case C:
          SETPORT(PORTC);
          break;
        case D:
          SETPORT(PORTD);
          break;
      }
  }
}
  else
  {
    // do nothing
  }
}
void DIO_VidInitialize (void)

{
  SETPORT(DDRA);
  SETPORT(DDRB);
  SETPORT(DDRC);
  SETPORT(DDRD);
  SETPORT(PORTA);
  SETPORT(PORTB);
  SETPORT(PORTC);
  SETPORT(PORTD);
}


