/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Properties for file
 */

#include <eos.h>
#include <video/tms99x8.h>
#include <smartkeys.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "directory.h"
#include "buffer.h"
#include "eos_filesystem.h"
#include "cursor.h"

const char *properties_month(unsigned char m)
{
  switch (m)
    {
    case 1:
      return "JAN";
    case 2:
      return "FEB";
    case 3:
      return "MAR";
    case 4:
      return "APR";
    case 5:
      return "MAY";
    case 6:
      return "JUN";
    case 7:
      return "JUL";
    case 8:
      return "AUG";
    case 9:
      return "SEP";
    case 10:
      return "OCT";
    case 11:
      return "NOV";
    case 12:
      return "DEC";
    }
}

const char *properties_yesno(bool b)
{
  if (b)
    return "Yes";
  else
    return "No";
}

unsigned long properties_filesize(DirectoryEntry *d)
{
  return (d->blocks_used-1)*1024+d->last_block_bytes_used;
}

void properties(void)
{
  DirectoryEntry *d = (DirectoryEntry *)buffer;
  char fn[12]={0,0,0,0,0,0,0,0,0,0,0,0};
  char ft=0;

  selector(false);
  
  directory_bkg();
  directory_bkg_remove_bluelines();

  // Put selected filename in tab
  vdp_color(1,15,7);
  directory_filename(d[current_entry],fn,&ft);
  gotoxy(3,1);
  cprintf("%s",fn);

  // File size in bytes
  gotoxy(17,1);
  vdp_color(1,7,7);
  cprintf("%8lu bytes",properties_filesize(d[current_entry]));

  // Date
  gotoxy(16,3);
  vdp_color(1,15,7);
  cprintf("DATE");
  vdp_color(1,7,7);
  d[current_entry].year = 84;
  d[current_entry].month= 04;
  d[current_entry].day=05;

  gotoxy(20,3);
  cprintf("%02u-%s-%02u",d[current_entry].year,properties_month(d[current_entry].month),d[current_entry].day);

  gotoxy(3,5);
  vdp_color(1,15,7);
  cprintf("%18s","START BLOCK ");
  vdp_color(1,7,7);
  cprintf("%6u",d[current_entry].start_block);

  gotoxy(3,6);
  vdp_color(1,15,7);
  cprintf("%18s","ALLOCATED BLOCKS ");
  vdp_color(1,7,7);
  cprintf("%6u",d[current_entry].allocated_blocks);

  gotoxy(3,7);
  vdp_color(1,15,7);
  cprintf("%18s","USED BLOCKS ");
  vdp_color(1,7,7);
  cprintf("%6u",d[current_entry].blocks_used);

  gotoxy(3,8);
  vdp_color(1,15,7);
  cprintf("%18s","LAST BLOCK BYTES ");
  vdp_color(1,7,7);
  cprintf("%6u",d[current_entry].last_block_bytes_used);

  gotoxy(3,10);
  vdp_color(1,15,7);
  cprintf("%18s","LOCKED? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x80));

  gotoxy(3,11);
  vdp_color(1,15,7);
  cprintf("%18s","WRITE PROTECTED? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x40));

  gotoxy(3,12);
  vdp_color(1,15,7);
  cprintf("%18s","READ PROTECTED? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x20));

  gotoxy(3,13);
  vdp_color(1,15,7);
  cprintf("%18s","USER FILE? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x10));

  gotoxy(3,14);
  vdp_color(1,15,7);
  cprintf("%18s","SYSTEM FILE? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x08));

  gotoxy(3,15);
  vdp_color(1,15,7);
  cprintf("%18s","DELETED? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x04));

  gotoxy(3,16);
  vdp_color(1,15,7);
  cprintf("%18s","EXEC PROTECTED? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x02));

  gotoxy(3,17);
  vdp_color(1,15,7);
  cprintf("%18s","BLOCKS LEFT FILE? ");
  vdp_color(1,7,7);
  cprintf("%6s",properties_yesno(d[current_entry].attributes & 0x01));

  state=MENU_PROPERTIES;

}

