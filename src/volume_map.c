/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Volume Map
 */

#include <eos.h>
#include <msx.h>
#include <smartkeys.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "directory.h"
#include "buffer.h"
#include "eos_filesystem.h"
#include "cursor.h"

#define MAP_X_START 3
#define MAP_Y_START 5

#define MAP_X_MAX 28
#define MAP_Y_MAX 15
#define BLOCKS_PER_PAGE 260

#define COLOR_UNKNOWN 15
#define COLOR_BOOT 4
#define COLOR_DIR 5
#define COLOR_BAD 6
#define COLOR_DATA 3
#define COLOR_ALLOCATED 2
#define COLOR_EMPTY 7
#define COLOR_LAST 11

static unsigned char directory_blocks_remaining=0;


unsigned long volume_map_page_block_begin(void)
{
  return BLOCKS_PER_PAGE * volume_map_page;
}  

unsigned long volume_map_page_block_end(void)
{
  return current_size - volume_map_page * BLOCKS_PER_PAGE;
}

void volume_map_plot(unsigned long block, unsigned char color, char c)
{
  unsigned char y=(block/26)+MAP_Y_START;
  unsigned char x=(block%26)+MAP_X_START;

  if (block>BLOCKS_PER_PAGE)
    return;
  
  gotoxy(x,y);
  msx_color(1,color,7);
  putch(c);
}

void volume_map(void)
{
  char tmp[80];
  char x=MAP_X_START;
  char y=MAP_Y_START;
  unsigned char r=0;
  unsigned short num_visible_blocks=0;
  char label[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  DirectoryEntry *d = (DirectoryEntry *)buffer;
  unsigned short map_end=0;
  
  selector(false);
  
  directory_bkg();
  directory_bkg_remove_bluelines();

  // print map range
  gotoxy(6,3);
  cprintf("BLOCKS ");
  msx_color(1,7,7);
  cprintf("%6lu",volume_map_page_block_begin());
  msx_color(1,15,7);
  cprintf(" TO ");
  msx_color(1,7,7);
  cprintf("%6lu",volume_map_page_block_end());
  
  // print legend  
  gotoxy(3,16);
  msx_color(1,COLOR_BOOT,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," BOOT");
  msx_color(1,COLOR_DIR,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," DIR");
  msx_color(1,COLOR_EMPTY,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," EMPTY");
  msx_color(1,COLOR_LAST,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-5s"," LAST");

  gotoxy(3,17);
  msx_color(1,COLOR_ALLOCATED,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," ALLOCATED   ");
  msx_color(1,COLOR_DATA,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," USED");
  msx_color(1,COLOR_BAD,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-5s"," BAD");

  
  // Put label in tab
  directory_label(current_device,label);
  gotoxy(3,1);
  msx_color(1,15,7);
  cprintf("%s",label);
  
  snprintf(tmp,sizeof(tmp),"   READING VOLUME MAP\n   FROM DEVICE %02x\n   PLEASE WAIT.",current_device);
  smartkeys_display(NULL,NULL,NULL,"  PAGE\n  UP","  PAGE\n  DOWN","  ABORT");
  smartkeys_status(tmp);

  current_block=0UL;

  if (current_size<BLOCKS_PER_PAGE)
    map_end=current_size;
  else
    map_end=BLOCKS_PER_PAGE;

  // pre-fill map area with empty blocks.
  
  for (unsigned short block=0;block<map_end;block++)
    volume_map_plot(block,COLOR_EMPTY,' ');

  gotoxy(0,0);

  d++;
  
  // Traverse through directory entries until we hit the BLOCKS LEFT entry
  do
    {
      unsigned long start_block=d->start_block;
      unsigned short allocated_blocks=d->allocated_blocks;
      unsigned short used_blocks=d->blocks_used;
      unsigned short current_block=d->start_block;
      unsigned char current_color=COLOR_DATA;
      char *fp = d->filename;
      bool fpdone = false;
      
      if (current_block==0)
	{
	  volume_map_plot(current_block,COLOR_BOOT,'B');
	  d++;
	  continue;
	}

      if (d->filename[0]=='D' &&
	  d->filename[1]=='I' &&
	  d->filename[2]=='R' &&
	  d->filename[3]=='E' &&
	  d->filename[4]=='C' &&
	  d->filename[5]=='T' &&
	  d->filename[6]=='O' &&
	  d->filename[7]=='R' &&
	  d->filename[8]=='Y' &&
	  d->filename[9]==0x03)
	current_color=COLOR_DIR;
	
      // Plot the used blocks, then allocated blocks.
      while (used_blocks--)
	{
	  if (*fp == 0x03)
	    fpdone=true;

	  if (!fpdone)
	    volume_map_plot(current_block++,current_color,*fp++);
	  else
	    volume_map_plot(current_block++,current_color,' ');
	  
	  allocated_blocks--;
	}

      while (allocated_blocks--)
	{
	  if (*fp == 0x03)
	    fpdone=true;

	  if (!fpdone)
	    volume_map_plot(current_block++,COLOR_ALLOCATED,*fp++);
	  else
	    volume_map_plot(current_block++,COLOR_ALLOCATED,' ');
	}
      // To next entry
      d++;
      
    } while(!entry_is_blocks_left(d));

  // Plot BLOCKS LEFT Entry
  volume_map_plot(d->start_block,COLOR_LAST,' ');
  
  state=MENU_MAP;
}
