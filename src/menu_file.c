/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose File Functions menu
 */

#include <eos.h>
#include <smartkeys.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "state.h"
#include "globals.h"

static const char *menu_item_select_files = " SELECT\n  FILES";

void menu_file(void)
{
  char tmp[48];

  selected_files=255;
  
  if (selected_files)
    snprintf(tmp,sizeof(tmp),"  %02u\nSELECTED",selected_files);
  else
    strncpy(tmp,menu_item_select_files,sizeof(tmp));
  
  smartkeys_display(NULL,NULL,tmp," RENAME\n  \x1f\x1f""FILE","  VIEW\n  \x1f""FILE","PROPERTIES");
  snprintf(tmp,sizeof(tmp),"   DEVICE %02u\n   SELECT FILE\n   OPERATION",current_device);
  smartkeys_status(tmp);
  
  eos_start_read_keyboard();

  while (state==MENU_FILE)
    {
      switch(input())
	{
	case 0x1b:
	  state=MENU_MAIN;
	case 0x83:
	  break;
	case 0x84:
	  break;
	case 0x85:
	  break;
	case 0x86:
	  state=PROPERTIES;
	  break;
	}
    }
  
  eos_end_read_keyboard();
}
