#include "usb_board.h"



/** LUFA CDC Class driver interface configuration and state information. This structure is
 *  passed to all CDC Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface =
 {
  .Config =
   {
    .ControlInterfaceNumber         = 0,

    .DataINEndpointNumber           = CDC_TX_EPNUM,
    .DataINEndpointSize             = CDC_TXRX_EPSIZE,
    .DataINEndpointDoubleBank       = false,

    .DataOUTEndpointNumber          = CDC_RX_EPNUM,
    .DataOUTEndpointSize            = CDC_TXRX_EPSIZE,
    .DataOUTEndpointDoubleBank      = false,

    .NotificationEndpointNumber     = CDC_NOTIFICATION_EPNUM,
    .NotificationEndpointSize       = CDC_NOTIFICATION_EPSIZE,
    .NotificationEndpointDoubleBank = false,
   },
 };

/** Standard file stream for the CDC interface when set up, so that the virtual CDC COM port can be
 *  used like any regular character stream in the C APIs
 */
static FILE USBSerialStream;

/** Main program entry point. This routine contains the overall program flow, including initial
 *  setup of all components and the main program loop.
 */
int main(void)
{
 SetupHardware();
 
 /* Create a regular character stream for the interface so that it can be used with the stdio.h functions */
 CDC_Device_CreateStream(&VirtualSerial_CDC_Interface, &USBSerialStream);
 sei();

   
   
  for(;;){ 
    CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
    USB_USBTask();
    Board_Task();
  }

 
}

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
 /* Disable watchdog if enabled by bootloader/fuses */
 MCUSR &= ~(1 << WDRF);
 wdt_disable();

 /* Disable clock division */
 clock_prescale_set(clock_div_1);

 /* Hardware Initialization */
 USB_Init();
 LED_Init_1();
 LED_Init_2();
 LED_Control_on();
 Buffer_init(IN_buffer);
}

void EVENT_USB_Device_ConfigurationChanged(void)
{
 CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);
 
}
void EVENT_USB_Device_UnhandledControlRequest(void)
{
 CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

/*
char * get_string(char *s,uint8_t byte){
 
 char *temp = &s;

  
  s[0] = byte;
  s[1] = NULL;
  return s;
}
*/

void Board_Task(){

  /* Must throw away unused bytes from the host, or it will lock up while waiting for the device */
  uint8_t rbyte = CDC_Device_ReceiveByte(&VirtualSerial_CDC_Interface);
  uint8_t i;
  char s, buffer_temp[20];
//  CDC_Device_SendByte(&VirtualSerial_CDC_Interface,"test\r\n");
  if (!(rbyte < 0)){
     if(zeichen(rbyte)){
         put_char( ((char)rbyte) ); 
         
                buffer_putc(&IN_buffer, (char)rbyte);
   
     }else{
       if((rbyte == '\r')){
         put_char( ((char)rbyte) ); 
         put_char('\n' ); 
         for(i=0 ; (s = buffer_getc(&IN_buffer)); i++ ){
            buffer_temp[i] = s;
         }          
         buffer_temp[i] = '\0';
//
//
//       
//
//
//
         
        switch(command(buffer_temp)){
          case 0: put_string("Unknown command\r\n"); 
                  break;
          case 1: command_1();  
                  break;
          case 2: command_2();  
                  break;
          case 3: command_3();  
                  break;
 
        }
           
      }
         
     }
  }
}

void command_1(){
   LED1_toggle();
} 

void command_2(){
   LED2_toggle();
} 
void command_3(){
   LED3_toggle();
} 



