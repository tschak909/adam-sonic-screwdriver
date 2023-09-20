/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Test harness (will be removed before release)
 */

#include <video/tms99x8.h>
#include <eos.h>
#include <conio.h>
#include "buffer.h"
#include "globals.h"

void test_harness(void)
{
  unsigned short cksum=0;
  
  buffer_fill(0x00);
  eos_read_block(0x05,0UL,buffer);

  for (unsigned short i=0;i<1024;i++)
    cksum += buffer[i];

  cprintf("CKSUM: %04x\n",cksum);
  
  state=HALT;
}
