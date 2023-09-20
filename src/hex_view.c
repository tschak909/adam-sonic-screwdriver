/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Hex View
 */

#include <video/tms99x8.h>
#include <eos.h>
#include <smartkeys.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "globals.h"
#include "cursor.h"

#define HEX_VIEW_NUM_LINES 19

char *header[33]="VOLUME BLOCK #0001";
char *footer[33]="OFF:0000/1024";

char hex_ascii_char(char c)
{
  return ((c > 0x1F) || (c < 0x80)) ? c : '.';
}

void hex_test_harness(void)
{
  smartkeys_set_mode();
  current_device=0x05;
  buffer_fill(0x00);
  eos_read_block(current_device,13UL,buffer);
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status("   HEX VIEWER TEST HARNESS");
}

void hex_view(void)
{
  unsigned char *hp=(unsigned char *)buffer, *ap=(unsigned char *)buffer;

  hex_test_harness();

  vdp_color(15,6,7);
  cprintf("%32s",header);

  for (int i=0;i<HEX_VIEW_NUM_LINES;i++)
    {
      vdp_color(1,15,7);
      for (int j=0;j<8;j++)
	{
	  cprintf("%02x ",*hp++);
	}
      vdp_color(15,4,7);
      for (int j=0;j<8;j++)
	{
	  cprintf("%c",hex_ascii_char(*ap++));
	}
    }

  vdp_color(15,6,7);
  cprintf("%32s",footer);
  
  cursor(true);
  cursor_pos(0,1);
  
  state=HALT;
}
