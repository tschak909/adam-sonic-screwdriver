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

State state=DIRECTORY;

void main(void)
{
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
	case HEX_VIEW:
	  hex_view();
	  break;
	case HALT:
	  halt();
	  break;
	}
    }
}
