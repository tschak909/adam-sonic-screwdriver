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

void menu_format_type_num_blocks(void)
{
  char tmp[48];

  smartkeys_display("33\nBLOCKS","77\nBLOCKS","116\nBLOCKS","155\nBLOCKS","194\nBLOCKS","233\nBLOCKS");

  eos_start_read_keyboard();
  
  while (state==MENU_FORMAT_TYPE_NUM_BLOCKS)
    {
      switch(input())
	{
	case 0x1B:
	  state=MENU_DRIVE;
	  break;
	case 0x81:
	  current_dirsize=1;
	  state=FORMAT_LABEL;
	  break;
	case 0x82:
	  current_dirsize=2;
	  state=FORMAT_LABEL;
	  break;
	case 0x83:
	  current_dirsize=3;
	  state=FORMAT_LABEL;
	  break;
	case 0x84:
	  current_dirsize=4;
	  state=FORMAT_LABEL;
	  break;
	case 0x85:
	  current_dirsize=5;
	  state=FORMAT_LABEL;
	  break;
	case 0x86:
	  current_dirsize=6;
	  state=FORMAT_LABEL;
	  break;
	default:
	  break;
	}
    }

  eos_end_read_keyboard();
}
