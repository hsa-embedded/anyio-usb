#ifndef _ZEICHEN_H_
#define _ZEICHEN_H_

 /*Includes*/
 #include <avr/io.h>
 #include "usb_board.h"
 /*Makros*/
 #define ZAHL_ANF 48
 #define ZAHL_END 57

 #define BUCHST_KL_ANF 97
 #define BUCHST_KL_END 122

 #define BUCHST_GR_ANF 65
 #define BUCHST_GR_END 90


 /*Functions Prototypes: */
 uint8_t zeichen(uint8_t data);
 uint8_t command(char *buffer);

#endif




