/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Main entrypoint
 */

#include <stdbool.h>
#include "state.h"
#include "splash.h"
#include "scan.h"
#include "directory.h"
#include "halt.h"

State state=DIRECTORY;

void main(void)
{
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
	case DIRECTORY:
	  directory();
	  break;
	case HALT:
	  halt();
	  break;
	}
    }
}
