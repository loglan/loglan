     /* Loglan82 Compiler&Interpreter
     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
     Copyright (C)  1993, 1994 LITA, Pau
     
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     
=======================================================================
*/

#include "graf.h"


#define bound(x,y)  ( x<0 || y<0 || x>719 || y>347 )


int pascal nocard( dummy )
   void *dummy;
{
   return 1;
}


#define index   0x3b4		/* 6845 ports */
#define data    0x3b5
#define mode    0x3b8		/* Herc ports */
#define status  0x3ba
#define config  0x3bf


static int cur_color;
static int cur_x;
static int cur_y;
static char *page_drawn;
static int page_drawn_no;
static int page_viewed;


#if WORD_32BIT
#define HERC_BASE 0xE00B0000UL
#define CHAR_BASE 0xE00FFA6EUL
#else
#define HERC_BASE 0xB0000000UL
#define CHAR_BASE 0xFFA6000EUL
#endif


static void set_page_drawn( page )
   int page;
{
   if( page == 0 || page == 1 )
   {
      page_drawn = (char *)( HERC_BASE + page * 0x8000);
      page_drawn_no = page;
   }
}


static void screen_off()
{
   outportb( mode, '\0' );
}


static void set_page_viewed( page )
   int page;
{
   if( page == 0 )  outportb( mode, '\x0a' );
   else
   if( page == 1 )  outportb( mode, '\x8a' );
   page_viewed = page;
}


static void clear_buffer( buf )
   char *buf;
{
   int i;
   for( i=0; i<0x7fff; i++ )  buf[i] = '\0';
}


static void clear_gr_scr( page )
   int page;
{
   if( page_viewed == page )  screen_off();
   clear_buffer( (char *)(HERC_BASE + page*0x8000) );
   if( page_viewed == page )  set_page_viewed( page );
}


static int in_graphics=0;
void pascal gron( dummy )
   int *dummy;
{
   char i;
   static char params[16] = {
      '\x35', '\x2d', '\x2e', '\x07', '\x5b', '\x02',
      '\x57', '\x57', '\x02', '\x03', '\x00', '\x00',
      '\x00', '\x00', '\x00', '\x00'
   };

   if( in_graphics )  return;
   in_graphics = 1;

   atexit( groff );

/*
   {
      int i=0;
      geninterrupt (0x11);
      if (( AX & 0x30 ) == 0x30)
         for (i=0; i<0x800; i++)
            if (inportb(status) & 0x80)
            {
               i=-1;
               break;
            }
      if( i != -1 )
      {
         fprintf( stderr, "This version runs only with HERCULES graphic card\n" );
         exit( 1 );
      }
   }
*/


   outportb( config, 3 );                   /* allows both graphics pages */
   screen_off();
   for( i=0; i<sizeof(params); i++) {
      outportb( index, i );
      outportb( data, params[i] );
   }
   set_page_viewed( 0 );
   set_page_drawn ( 0 );
   clear_gr_scr( 1 );
   clear_gr_scr( 0 );
   cur_color=1;
   cur_x=0;
   cur_y=0;
}


void pascal groff()
{
   char i;
   static char params[16] = {
      0x61, 0x50, 0x52, 0x0f, 0x19, 0x06,
      0x19, 0x19, 0x02, 0x0d, 0x0b, 0x0c,
      0x00, 0x00, 0x00, 0x00
   };

   if( !in_graphics )  return;
   in_graphics = 0;

   outportb( config, 0 );                       /* lock out graphics mode */
   screen_off();
   for( i=0; i<sizeof(params); i++) {
      outportb( index, i );
      outportb( data, params[i] );
   }
   outportb( mode, '\x28' );           /* enable blink and turn on screen */
}


void pascal hpage( nr, tryb, zeruj )
   int *nr,*tryb,*zeruj;
{
   if( *nr == 0 )
   {
      if( *zeruj )  clear_gr_scr( 0 );
      if( *tryb ==  1 )  set_page_viewed( 0 );
      if( *tryb == -1 )  set_page_viewed( 0 );
   }
   else
   if( *nr == 1 )
   {
      if( *zeruj )  clear_gr_scr( 1 );
      if( *tryb ==  1 )  set_page_viewed( 1 );
      if( *tryb == -1 )  set_page_viewed( 1 );
   }
}


void pascal video( buffer )
   char *buffer;
{
   page_drawn = buffer;
   page_drawn_no = -1;
}


void pascal cls()
{
   if( page_viewed == page_drawn_no )  clear_gr_scr( page_viewed );
   else  clear_buffer( page_drawn );
}


void pascal point( col, row )
   int *col,*row;
{
   int x=*col, y=*row;
   int byte_ofs;      /* offset within page for byte containing the point */
   char mask;                            /* locates point within the byte */
   if( bound( *col, *row ) )  return;
   mask = 1 << (7 - (x % 8));
   byte_ofs = 0x2000 * (y % 4) + 90 * (y/4) + (x/8);
   if( cur_color == 1 )                                /* draw the point */
      page_drawn[ byte_ofs ] |= mask;
   else                                                /* erase the point */
      page_drawn[ byte_ofs ] &= ~mask;
   move( col, row );
}


void pascal move( col, row )
   int *col,*row;
{
   cur_x = *col;
   cur_y = *row;
}


int pascal inxpos( dummy ) void *dummy; {  return cur_x;  }
int pascal inypos( dummy ) void *dummy; {  return cur_y;  }


int pascal inpix( col, row )
   int *col,*row;
{
   int x=*col, y=*row;
   int byte_ofs;      /* offset within page for byte containing the point */
   char mask;                            /* locates point within the byte */
   if( bound( *col, *row ) )  return 0;
   move( col, row );
   mask = 1 << (7 - (x % 8));
   byte_ofs = 0x2000 * (y % 4) + 90 * (y/4) + (x/8);
   return !!( page_drawn[ byte_ofs ] & mask );
}


void pascal color( c )
   int *c;
{
   cur_color = *c;
}


void pascal intens( intensity )  int *intensity;  {}
void pascal pallet( palette   )  int *palette;    {}
void pascal border( color     )  int *color;      {}
void pascal style ( style_no  )  int *style_no;   {}
void pascal patern( p1,p2,p3,p4 ) int *p1,*p2,*p3,*p4; {}


static struct { int x,y,c; } stack[16];
static int stack_top=0;
void pascal pushxy()
{
   stack[stack_top  ].x = cur_x;
   stack[stack_top  ].y = cur_y;
   stack[stack_top++].c = cur_color;
}
void pascal popxy()
{
   cur_x     = stack[--stack_top].x;
   cur_y     = stack[  stack_top].y;
   cur_color = stack[  stack_top].c;
}


void pascal track ( x, y )  int *x,*y;  {}

static char *char_base = (char *)CHAR_BASE;
void pascal hascii( chrp )
   int *chrp;
{
   int i,j;
   int chr = (*chrp) & 0x7F;
   int x00 = inxpos(NULL);
   int y00 = inypos(NULL);
   pushxy();
   if( chr == 0 )
   {
      int col = cur_color;
      cur_color = 0;
      for( i=x00; i<x00+8; i++ )  for( j=y00; j<y00+8; j++ )  point(&i,&j);
      cur_color = col;
   }
   else
   {
      char *c = char_base + 8*chr;
      for( i=x00; i<x00+8; i++ )  for( j=y00; j<y00+8; j++ )
         if( !!( c[j-y00] & (0x80>>(i-x00)) ) )
            point(&i,&j);
   }
   popxy();
   if( chr != 0 )
   {
      x00 += 8;
      move( &x00, &y00 );
   }
}
void pascal hfont ( seg, ofs )  int *seg,*ofs;  {}
void pascal hfont8( seg, ofs )  int *seg,*ofs;  {}


