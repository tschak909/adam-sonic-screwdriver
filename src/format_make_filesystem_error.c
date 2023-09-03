/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Bad Block error, retry (yes/no)
 */

#include <eos.h>
#include <smartkeys.h>
#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "directory.h"

void format_make_filesystem_error(void)
{
  char tmp[48];

  snprintf(tmp,sizeof(tmp),"   DEVICE %02u\n   BAD BLOCK ERROR\n   RETRY?",current_device);
  smartkeys_display(NULL,NULL,NULL,NULL,"   YES","    NO");
  smartkeys_status(tmp);

  eos_start_read_keyboard();
  
  while (state==FORMAT_MAKE_FILESYSTEM_ERROR)
    {
      switch(input())
	{
	case 0x85:
	  state=FORMAT_MAKE_FILESYSTEM;
	  break;
	case 0x1B:
	case 0x86:
	  state=MENU_DRIVE;
	  break;
	default:
	  break;
	}
    }

  eos_end_read_keyboard();
}
