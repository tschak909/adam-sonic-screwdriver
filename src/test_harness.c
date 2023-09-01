/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Test harness (will be removed before release)
 */

#include <msx.h>
#include <eos.h>
#include "buffer.h"
#include "globals.h"

void test_harness(void)
{
  buffer_fill(0x00);

  cprintf("Blanking first 12 blocks in device 05\n");

  for (unsigned long i=0UL;i<13UL;i++)
    {
      cprintf("WRITING BLOCK %3ul\n");
      eos_write_block(0x05,i,buffer);
    }

  cprintf("DONE.\n");
  state=HALT;
}
