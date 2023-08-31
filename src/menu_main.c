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
#include "input.h"
#include "state.h"
#include "globals.h"

void menu_main(void)
{
  smartkeys_display(NULL,NULL,NULL,"  FILE\n FUNCS"," DRIVE\n FUNCS","  CHANGE\n  DRIVE");
  smartkeys_status(" COMING SOON:\n ADAM'S SONIC SCREWDRIVER\n");

  eos_start_read_keyboard();
  
  while (state==MENU_MAIN)
    {
      switch(input())
	{
	case 0x84:
	  state=MENU_FILE;
	  break;
	case 0x85:
	  break;
	case 0x86:
	  state=SELECT_DRIVE;
	  break;
	default:
	  // handle_navigation_keys();
	  break;
	}
    }

  eos_end_read_keyboard();
}
