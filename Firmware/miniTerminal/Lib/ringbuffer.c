/*
* Ringbuffer
*
*
*/


#include "ringbuffer.h"


char buffer_putc(struct buffer *bp, char c){
 
 if(((bp->head+1) == bp->tail) ||
   (bp->tail==0 && ((bp->head+1) & (1<<BITS_SIZE)))) 
   return 0; /* Buffer voll */
  
 if((++(bp->head)) & (1 << BITS_SIZE)) //wenn "head" am Bufferende
   bp->head=0x00; // dann wieder auf Anfang setzen
 bp->data[bp->head] = c; //Zeichen in Buffer schreiben
 return c;
} 

void buffer_puts(struct buffer *bp, char *sp){
 while(*sp){
   buffer_putc(bp,*sp);
   sp++;
 }
}

char buffer_getc(struct buffer *bp){
 if(bp->head==bp->tail)
   return 0; //Buffer leer
 if((++(bp->tail )) & (1<< BITS_SIZE)) //wenn "tail" am Bufferende
   bp->tail=0;                         // wieder auf Anfang setzen
 return bp->data[bp->tail];
}
