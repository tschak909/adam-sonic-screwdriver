/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Check for bad blocks menu
 */

#include <eos.h>
#include <smartkeys.h>
#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "directory.h"

void menu_check_for_bad_blocks(void)
{
  char tmp[48];

  snprintf(tmp,sizeof(tmp),"   DEVICE %02u\n   CHECK FOR BAD BLOCKS?",current_device);
  smartkeys_display(NULL,NULL,NULL,NULL,"  YES","  NO");
  smartkeys_status(tmp);

  eos_start_read_keyboard();
  
  while (state==MENU_CHECK_FOR_BAD_BLOCKS)
    {
      switch(input())
	{
	case 0x1B:
	  state=MENU_DRIVE;
	  break;
	case 0x85:
	  state=CHECK_FOR_BAD_BLOCKS;
	  break;
	case 0x86:
	  state=MENU_FORMAT_TYPE;
	  break;
	default:
	  break;
	}
    }

  eos_end_read_keyboard();
}
