/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Main entrypoint
 */

#include <smartkeys.h>
#include <stdbool.h>
#include "state.h"
#include "splash.h"
#include "scan.h"
#include "select_drive.h"
#include "directory.h"
#include "hex_view.h"
#include "halt.h"
#include "globals.h"
#include "menu_main.h"
#include "menu_file.h"
#include "menu_drive.h"
#include "properties.h"
#include "volume_map.h"
#include "menu_map.h"
#include "menu_properties.h"

State state=SCAN;

void main(void)
{
  // Set current device to boot device
  current_device = (*(unsigned char *)0xFD6F);

  smartkeys_sound_init();
  
  while(true)
    {
      switch(state)
	{
	case SPLASH:
	  splash();
	  break;
	case SCAN:
	  scan();
	  break;
	case SELECT_DRIVE:
	  select_drive();
	  break;
	case DIRECTORY:
	  directory();
	  break;
	case MENU_MAIN:
	  menu_main();
	  break;
	case MENU_FILE:
	  menu_file();
	  break;
	case MENU_DRIVE:
	  menu_drive();
	  break;
	case HEX_VIEW:
	  hex_view();
	  break;
	case PROPERTIES:
	  properties();
	  break;
	case MENU_PROPERTIES:
	  menu_properties();
	  break;
	case VOLUME_MAP:
	  volume_map();
	  break;
	case MENU_MAP:
	  menu_map();
	  break;
	case HALT:
	  halt();
	  break;
	}
    }
}
