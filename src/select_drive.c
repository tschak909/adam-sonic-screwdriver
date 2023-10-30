/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Select drive
 */

#include <stdlib.h>
#include <smartkeys.h>
#include <eos.h>
#include "input.h"
#include "state.h"
#include "directory.h"
#include "globals.h"

void select_drive(void)
{
  smartkeys_display("  \x1f\x1f\x1f\x1f""DEVICE\n     4"," \x1f\x1f""DEVICE\n   \x1f\x1f""5"," \x1f\x1f""DEVICE\n   \x1f\x1f""6"," \x1f\x1f""DEVICE\n   \x1f\x1f""7"," \x1f\x1f""DEVICE\n   \x1f\x1f""8"," \x1f\x1f\x1f""DEVICE\n   18");

  eos_start_read_keyboard();

  while (state==SELECT_DRIVE)
    {
      switch(input())
	{
	case 0x81:
	  current_device=4;
	  state=SCAN;
	  break;
	case 0x82:
	  current_device=5;
	  state=SCAN;
	  break;
	case 0x83:
	  current_device=6;
	  state=SCAN;
	  break;
	case 0x84:
	  current_device=7;
	  state=SCAN;
	  break;
	case 0x85:
	  current_device=8;
	  state=SCAN;
	  break;
	case 0x86:
	  current_device=0x18;
	  state=SCAN;
	  break;
	}
    }
  
  eos_end_read_keyboard();
}
