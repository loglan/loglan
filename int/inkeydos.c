#include "graf\graf.h"
#include <dos.h>

static union REGS r;

int pascal inkey( dummy )
   void *dummy;
{
   r.h.ah = 0x01;
   int86( 0x16, &r, &r);
   if( r.x.ax == 0 )  return 0;
   else
   {
      r.h.ah = 0x00;
      int86( 0x16, &r, &r);
      if( r.h.al != '\0' )
         return (int)(unsigned char)( r.h.al );
      else
         if( r.h.ah & '\x80' )
            return (int)( -r.h.ah );
         else
            return (int)(unsigned char)( r.h.ah );
   }
}

