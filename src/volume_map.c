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

#define COLOR_UNKNOWN 15
#define COLOR_BOOT 4
#define COLOR_DIR 5
#define COLOR_BAD 6
#define COLOR_DATA 3
#define COLOR_EMPTY 7
#define COLOR_LAST 11

static unsigned char directory_blocks_remaining=0;

void volume_map_eos_block_color(void)
{
  unsigned char c=0;

  if (current_block==0)
    return COLOR_BOOT;

  if (current_block==1) // Beginning of directory
    {
      DirectoryEntry *d;
      unsigned long block=0;
      unsigned char r=0;
      
      if (eos_find_file_1("DIRECTORY\x03",d,&block,current_device))
	return COLOR_BAD;

      directory_blocks_remaining=d->allocated_blocks-1;
      return COLOR_DIR;
    }
  
  if (directory_blocks_remaining) // contiguous directory blocks remaining
    {
      directory_blocks_remaining--;
      return COLOR_DIR;
    }

  c=buffer[0];
  
  for (unsigned short i=0;i<1024;i++)
    {
      if (buffer[i] != c)
	return COLOR_DATA;
    }
  
  return COLOR_EMPTY;
}

void volume_map(void)
{
  char tmp[80];
  char x=MAP_X_START;
  char y=MAP_Y_START;
  unsigned char r=0;
  unsigned short num_visible_blocks=0;
  char label[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

  selector(false);
  
  directory_bkg();
  directory_bkg_remove_bluelines();

  // print legend

  gotoxy(16,3);
  msx_color(1,COLOR_DATA,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf(" = 1 BLOCK");
  
  gotoxy(6,16);
  msx_color(1,COLOR_BOOT,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," BOOT");
  msx_color(1,COLOR_DIR,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," DIR");
  msx_color(1,COLOR_DATA,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," DATA");

  gotoxy(6,17);
  msx_color(1,COLOR_EMPTY,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," EMPTY");
  msx_color(1,COLOR_BAD,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," BAD");
  msx_color(1,COLOR_LAST,7);
  putch(' ');
  msx_color(1,15,7);
  cprintf("%-6s"," LAST");

  // Put label in tab
  directory_label(current_device,label);
  gotoxy(3,1);
  msx_color(1,15,7);
  cprintf("%s",label);
  
  snprintf(tmp,sizeof(tmp),"   READING VOLUME MAP FROM DEVICE %02x\n   PLEASE WAIT.",current_device);
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,"  ABORT");
  smartkeys_status(tmp);

  current_block=0UL;
  
  while (y<MAP_Y_MAX)
    {
      char k=0;
      
      eos_start_read_keyboard();

      gotoxy(x++,y);

      // Read block into buffer
      r=eos_read_block(current_device,current_block,buffer);
    
      // Break if we hit end
      if (current_block>current_size) // We got some sort of error.
	break;
      else if (r==0x16) // media error
	msx_color(1,COLOR_BAD,7);
      else
	{
	  // determine block color based on valid data
	  msx_color(1,volume_map_eos_block_color(),7);
	}
	
      // Plot the block
      putch(' ');
      num_visible_blocks++;

      if (x>MAP_X_MAX)
	{
	  x=MAP_X_START;
	  y++;
	}

      k=eos_end_read_keyboard();

      if (k==0x86) // We asked for abort
	break;
      
      current_block++;
    }

  state=MENU_MAP;
}
