/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Format Type Menu
 */

#include <eos.h>
#include <smartkeys.h>
#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "directory.h"

void menu_format_type(void)
{
  char tmp[48];

  snprintf(tmp,sizeof(tmp),"   DEVICE %02u\n   SELECT FILESYSTEM TYPE\n   FOR THIS DISK",current_device);
  smartkeys_display(NULL,NULL,NULL,NULL,"  CP/M","  EOS");
  smartkeys_status(tmp);

  eos_start_read_keyboard();
  
  while (state==MENU_FORMAT_TYPE)
    {
      switch(input())
	{
	case 0x1B:
	  state=MENU_DRIVE;
	  break;
	case 0x85:
	  current_filesystem=CPM;
	  state=MENU_DRIVE;
	  break;
	case 0x86:
	  current_filesystem=EOS;
	  state=FORMAT_MAKE_FILESYSTEM;
	  break;
	default:
	  break;
	}
    }

  eos_end_read_keyboard();
}
