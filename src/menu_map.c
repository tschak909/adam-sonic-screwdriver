/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Drive menu
 */

#include <eos.h>
#include <smartkeys.h>
#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "volume_map.h"

void menu_map(void)
{
  char tmp[48];

  /* snprintf(tmp,sizeof(tmp),"   DEVICE %02u\n   %4uK SIZE\n   %4luK FREE",current_device,current_size,current_free); */
  /* smartkeys_display(NULL,NULL,NULL,"  FILE\n FUNCS"," DRIVE\n FUNCS","  CHANGE\n  DRIVE"); */
  /* smartkeys_status(tmp); */

  smartkeys_display(NULL,NULL," SELECT\n DRIVE","  PREV\n  PAGE","   NEXT\n   PAGE","BAD BLOCK\n   MAP");
  snprintf(tmp,sizeof(tmp),"   VOLUME MAP\n   FOR DEVICE %02x",current_device);
  smartkeys_status(tmp);
  
  eos_start_read_keyboard();
  
  while (state==MENU_MAP)
    {
      switch(input())
	{
	case 0x0d:
	  volume_map_view_block();
	  break;
	case 0x1B:
	  state=DIRECTORY;
	  break;
	case 0x80:
	  volume_map_cursor_home();
	  break;
	case 0x83:
	  break;
	case 0x84:
	  state=SELECT_DRIVE;
	  break;
	case 0x85:
	  break;
	case 0x86:
	  state=VOLUME_MAP_BAD_BLOCKS;
	  break;
	case 0x90:
	  wildcard_mode=!wildcard_mode;
	  break;
	case 0xA0:
	  volume_map_cursor_up();
	  break;
	case 0xA1:
	  volume_map_cursor_right();
	  break;
	case 0xA2:
	  volume_map_cursor_down();
	  break;
	case 0xA3:
	  volume_map_cursor_left();
	  break;
	}
    }

  eos_end_read_keyboard();
}
