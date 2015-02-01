#ifndef _USB_BOARD_H_
#define _USB_BOARD_H_

 /* Includes: */
  #include <avr/io.h>
  #include <avr/wdt.h>
  #include <avr/power.h>
//  #include <avr/string.h>
  #include <string.h>
  #include <stdio.h>
  #include <util/delay.h>

  #include "Descriptors.h"
  #include "Lib/ringbuffer.h"
  #include "Lib/zeichen.h"

  #include <LUFA/Version.h>
  #include <LUFA/Drivers/USB/USB.h>
  #include <LUFA/Drivers/USB/Class/CDC.h>

 /* Macros: */

 #define LED_on(var, bit) ((var) |= (1 << (bit))) 
 #define LED_off(var, bit) ((var) &= ~ (1 << (bit)))
 #define LED_toggle(var, bit) ((var) ^= (1 << (bit)))

 #if (defined(__AVR_AT90USB162__) || defined(__AVR_AT90USB82__)) 

  #define LED_Init_1() (DDRD |=  (1 << DDD0)    | (1 << DDD1)  | (1 << DDD5) |  (1 << DDD6) | (1 << DDD7) | (1<< DDD4)) 
  #define LED_Init_2() (DDRB |=  (1 << DDB5)    | (1 << DDB6)  | (1 << DDB7) |  (1 << DDB4))
 
  #define LED1_on() LED_on(PORTD, 0)
  #define LED2_on() LED_on(PORTD, 1)
  #define LED3_on() LED_on(PORTB, 4)
  #define LED4_on() LED_on(PORTD, 5)
  #define LED5_on() LED_on(PORTD, 6) 
  #define LED6_on() LED_on(PORTB, 5) 
  #define LED7_on() LED_on(PORTB, 6)
  #define LED8_on() LED_on(PORTB, 7)
  #define LED_Control_on() LED_on(PORTD, 4)

  
  #define LED1_off() LED_off(PORTD, 0)
  #define LED2_off() LED_off(PORTD, 1)
  #define LED3_off() LED_off(PORTB, 4)
  #define LED4_off() LED_off(PORTD, 5)
  #define LED5_off() LED_off(PORTD, 6) 
  #define LED6_off() LED_off(PORTB, 5) 
  #define LED7_off() LED_off(PORTB, 6)
  #define LED8_off() LED_off(PORTB, 7)
  #define LED_Control_off() LED_off(PORTD, 4)
 
  #define LED1_toggle() LED_toggle(PORTD, 0)
  #define LED2_toggle() LED_toggle(PORTD, 1)
  #define LED3_toggle() LED_toggle(PORTB, 4)
  #define LED4_toggle() LED_toggle(PORTD, 5)
  #define LED5_toggle() LED_toggle(PORTD, 6) 
  #define LED6_toggle() LED_toggle(PORTB, 5) 
  #define LED7_toggle() LED_toggle(PORTB, 6)
  #define LED8_toggle() LED_toggle(PORTB, 7)

 #endif
 

 
 #if (defined(__AVR_ATmega16U4__)  || defined(__AVR_ATmega32U4__))

  #define LED_Init_1() (DDRD |= (1 << DDD1) | (1 << DDD2) | (1 << DDD3)| (1 << DDD5))
  #define LED_Init_2() (PORTD |= (1 << DDD1) | (1 << DDD2) | (1 << DDD3)| (1 << DDD5))
   
  #define LED1_off() LED_on(PORTD, 0)
  #define LED2_off() LED_on(PORTD, 1)
  #define LED3_off() LED_on(PORTD, 2)
  #define LED_Control_off() LED_on(PORTD, 5)
    
  #define LED1_on() LED_off(PORTD, 3)
  #define LED2_on() LED_off(PORTD, 2)
  #define LED3_on() LED_off(PORTD, 1)
  #define LED_Control_on() LED_off(PORTD, 5)
 
  #define LED1_toggle() LED_toggle(PORTD, 3)
  #define LED2_toggle() LED_toggle(PORTD, 2)
  #define LED3_toggle() LED_toggle(PORTD, 1)
    
 #endif


 
 #define put_rbyte() fputs(get_string(s,rbyte),&USBSerialStream)
 #define put_string(var) fputs((var),&USBSerialStream)
 #define put_char(var) fputc((var),&USBSerialStream)

 #define COMMAND1 "reset\0"
 #define COMMAND2 "start\0"
 #define COMMAND3 "stop\0"


 /* Function Prototypes: */
  void SetupHardware(void);

  void EVENT_USB_Device_ConfigurationChanged(void);
  void EVENT_USB_Device_UnhandledControlRequest(void);
  char *  get_string(char * s,uint8_t byte);
  void Board_Task(void);
  void command_1(void);
  void command_2(void);
  void command_3(void);
#endif
