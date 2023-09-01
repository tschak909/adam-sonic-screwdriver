/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Main Menu
 */

#include <eos.h>
#include <smartkeys.h>
#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "directory.h"

void menu_main(void)
{
  char tmp[48];

  snprintf(tmp,sizeof(tmp),"   DEVICE %02u\n   %4uK SIZE\n   %4luK FREE",current_device,current_size,current_free);
  smartkeys_display(NULL,NULL,NULL,"  FILE\n FUNCS"," DRIVE\n FUNCS","  CHANGE\n  DRIVE");
  smartkeys_status(tmp);

  eos_start_read_keyboard();
  
  while (state==MENU_MAIN)
    {
      switch(input())
	{
	case 0x84:
	  state=MENU_FILE;
	  break;
	case 0x85:
	  state=MENU_DRIVE;
	  break;
	case 0x86:
	  state=SELECT_DRIVE;
	  break;
	case 0x90:
	  wildcard_mode=!wildcard_mode;
	  state=DIRECTORY;
	  break;
	case 0xA0:
	  directory_up();
	  break;
	case 0xA1:
	  directory_right();
	  break;
	case 0xA2:
	  directory_down();
	  break;
	case 0xA3:
	  directory_left();
	  break;
	default:
	  break;
	}
    }

  eos_end_read_keyboard();
}
