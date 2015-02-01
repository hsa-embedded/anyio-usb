#ifndef _RINGBUFFER_H_
#define _RINGBUFFER_H_

 /*Includes: */
 #include <inttypes.h>

 /* Makros: */
 #define BITS_SIZE 6
 #define Buffer_init(b) b.head=b.tail=0

  struct buffer{
     char data[1 << BITS_SIZE];
     uint8_t head, tail;
  } IN_buffer;
 /*Functions Prototypes: */

 char buffer_putc(struct buffer *bp, char c);
 void buffer_puts(struct buffer *bp, char *sp);
 char buffer_getc(struct buffer *bp);

#endif

