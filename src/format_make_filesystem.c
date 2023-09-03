/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Retension
 */

#include <eos.h>
#include <msx.h>
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

void format_make_filesystem(void)
{
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status("   ERASING DIRECTORY BLOCKS.");

  buffer_fill(0x00); // Fill block with zeroes, so EOS MAKE DIRECTORY is happy
  
  for (unsigned long block=1; block<13; block++) // skip block 0, because we wrote a boot record there.
    {
      if (eos_write_block(current_device,block,buffer) == 0x16)
	{
	  state=FORMAT_MAKE_FILESYSTEM_ERROR;
	  return;
	}
    }

  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status("   MAKING FILESYSTEM.");

  eos_initialize_directory(current_device,current_dirsize,current_size,current_label);
  
  state=SCAN;
}
