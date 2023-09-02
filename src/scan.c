/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Scan for devices
 */

#include <stdlib.h>
#include <smartkeys.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include "globals.h"
#include "scan.h"
#include "state.h"
#include "eos_filesystem.h"
#include "cpm_filesystem.h"
#include "buffer.h"
#include "input.h"

// Attempt to detect disk size, tape size always returns 256

void scan_block_size(void)
{
  char tmp[80];

  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  snprintf(tmp,sizeof(tmp),"   SCANNING DEVICE %02x VOLUME CAPACITY...",current_device);
  smartkeys_status(tmp);
  
  if (current_device == 0x08 || current_device == 0x18)
    {
      current_size=256;
      return;
    }

  // Otherwise attempt capacity scan
  if (eos_read_block(current_device,1439UL,buffer)==0x80)
    {
      current_size=1440;
      return;
    }
  else if (eos_read_block(current_device,719UL,buffer)==0x80)
    {
      current_size=720;
      return;
    }
  else if (eos_read_block(current_device,359UL,buffer)==0x80)
    {
      current_size=360;
    }
  else if (eos_read_block(current_device,319UL,buffer)==0x80)
    {
      current_size=320;
    }
  else if (eos_read_block(current_device,255UL,buffer)==0x80)
    {
      current_size=256;
    }
  else if (eos_read_block(current_device,159UL,buffer)==0x80)
    {
      current_size=160;
    }    
}

bool valid_diskette(void)
{
  char tmp[40];
  
  current_filesystem=UNKNOWN_FILESYSTEM;

  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  snprintf(tmp,40,"   SCANNING DEVICE %02x\n   PLEASE WAIT",current_device);
  smartkeys_status(tmp);
  
  if (volume_is_eos_filesystem(current_device))
    {
      current_filesystem=EOS;
      scan_block_size();
      current_free = eos_volume_free(current_device);
      return current_filesystem;
    }
  /* else if (volume_is_cpm_filesystem(current_device)) */
  /*   { */
  /*     current_filesystem=CPM; */
  /*     return current_filesystem; */
  /*   } */

  return current_filesystem;
}

void invalid_diskette(void)
{
  char tmp[128];
  
  snprintf(tmp,sizeof(tmp),"  THE VOLUME IN DEVICE %2u\n  DOES NOT CONTAIN A VALID\n  EOS OR CP/M FILE SYSTEM.",current_device);
  smartkeys_display(NULL,NULL,NULL,NULL," \x1f\x1fRETRY"," SELECT\n ANOTHER");
  smartkeys_status(tmp);

  eos_start_read_keyboard();

  while (state==SCAN)
    {
      switch(input())
	{
	case 0x85:
	  return;
	case 0x86:
	  state=SELECT_DRIVE;
	  break;
	}
    }

  eos_end_read_keyboard();
}

void scan(void)
{
  while (state==SCAN)
    {
      DCB *dcb = NULL;

      eos_scan_for_devices();
      
      if (!valid_diskette())
	invalid_diskette();
      else
	state=DIRECTORY;
    }
}
