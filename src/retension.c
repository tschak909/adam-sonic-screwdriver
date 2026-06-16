/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Retension
 */

#include <eos.h>
#include <video/tms99x8.h>
#include <smartkeys.h>
#include <conio.h>
#include "directory.h"
#include "state.h"
#include "rleunpack.h"
#include "eos_filesystem.h"
#include "cpm_filesystem.h"
#include "buffer.h"
#include "globals.h"
#include "input.h"
#include "cursor.h"

void retension(void)
{
  unsigned long end_block=0;
  DCB *dcb = eos_find_dcb(current_device);
  unsigned char k=0;
  
  smartkeys_display(NULL,NULL,NULL,NULL," RIGHT\n  DIR"," CENTER\n  DIR");
  smartkeys_status("   SELECT TAPE TYPE\n   [ESCAPE] TO ABORT");

  eos_start_read_keyboard();

  while (k<2)
    {
      k=input();
      
      switch(k)
	{
	case 0x1b:
	  state=MENU_DRIVE;
	  return;
	case 0x85:
	  end_block=0x7F;
	  break;
	case 0x86:
	  end_block=0x3F;
	  break;
	default:
	  k=1;
	  break;
	}
    }
  eos_end_read_keyboard();
  
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status("   MOVING TO END OF DATA PACK");
  
  eos_read_block(current_device,end_block,buffer);

  // Move to beginning, this is very asynchronous, and must be confirmed.
  
  dcb->block = 0;
  dcb->status = 2; // reset

  while (dcb->status < 0x80);

  eos_start_read_keyboard();

  smartkeys_display(NULL,NULL,NULL,NULL,NULL,"   DONE");
  smartkeys_status("   WAIT FOR TAPE TO FINISH REWINDING\n   THEN PRESS DONE.");

  while (eos_end_read_keyboard() != 0x86);

  state=SCAN;
}
