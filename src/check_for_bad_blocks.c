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
#include "scan.h"

void check_for_bad_blocks(void)
{
  scan_block_size();

  vdp_color(1,15,7);

  for (unsigned long i=0;i<current_size;i++)
    {
      gotoxy(3,19);

      cprintf("CHECKING %5lu of %5u",i,current_size-1);

      if (eos_read_block(current_device,i,buffer) == 0x16) // Media error.
	{
	  state=CHECK_FOR_BAD_BLOCKS_RETRY;
	  return;
	}
    }
  
  state=MENU_FORMAT_TYPE;
}
