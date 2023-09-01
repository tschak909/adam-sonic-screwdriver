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
#include "cursor.h"

#define PROPERTIES_POS_MAX 11

// Screen positions for selector
unsigned char properties_x[]={29,27,27,27,27,27,27,27,27,27,27,27,27};
unsigned char properties_y[]={3,5,6,7,8,10,11,12,13,14,15,16,17};

void properties_cursor_update(void)
{
  selector(2);
  selector_pos(properties_x[properties_pos],properties_y[properties_pos]);
}

void properties_up(void)
{
  if (!properties_pos)
    return;
  else
    properties_pos--;
  
  properties_cursor_update();
}

void properties_down(void)
{
  if (properties_pos>PROPERTIES_POS_MAX)
    return;
  else
    properties_pos++;
  
  properties_cursor_update();
}

void menu_properties(void)
{
  unsigned char x=properties_x[0];
  unsigned char y=properties_y[0];
  unsigned char pos=0;

  properties_cursor_update();
  
  smartkeys_display(NULL,NULL,"  VIEW\n  HEX","  VIEW\n  TEXT"," RENAME","  \x1f""EDIT\n\x1f\x1f\x1fMETADATA");
  smartkeys_status(" FILE PROPERTIES\n SELECT OPERATION\n OR ESCAPE.");

  eos_start_read_keyboard();
  
  while (state==MENU_PROPERTIES)
    {
      switch(input())
	{
	case 0x1b:
	  state=DIRECTORY;
	  break;
	case 0xA0:
	  properties_up();
	  break;
	case 0xA2:
	  properties_down();
	  break;
	}
    }

  eos_end_read_keyboard();
}
