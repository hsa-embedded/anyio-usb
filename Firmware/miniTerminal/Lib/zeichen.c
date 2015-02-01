#include "zeichen.h"

uint8_t zeichen(uint8_t data){

      if(  (data >= BUCHST_GR_ANF && data <= BUCHST_GR_END) || (data >= BUCHST_KL_ANF && data <= BUCHST_KL_END) || (data >= ZAHL_ANF && data <= ZAHL_END) )
         return 1;
      else 
         return 0;

   return 0;
}


uint8_t command(char *buffer){
 



     if(!(strcmp(COMMAND1, buffer))){
           return 1;
     }

     if(!(strcmp(COMMAND2, buffer))){
           return 2;
     }
    
     
     if(!(strcmp(COMMAND3, buffer))){
           return 3;
     }
    
    return 0;
          
     

     


}
