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

bool valid_diskette(void)
{
  current_filesystem=UNKNOWN_FILESYSTEM;
  
  if (volume_is_eos_filesystem(current_device))
    current_filesystem=EOS;
  else if (volume_is_cpm_filesystem(current_device))
    current_filesystem=CPM;

  return current_filesystem;
}

void invalid_diskette(void)
{
  char tmp[128];

  snprintf(tmp,sizeof(tmp),"  THE VOLUME IN DEVICE %2u\n  DOES NOT CONTAIN A VALID\n  EOS OR CP/M FILE SYSTEM.",current_device);
  smartkeys_display(NULL,NULL,NULL,NULL," \x1f\x1fRETRY"," SELECT\n ANOTHER");
  smartkeys_status(tmp);
  
}

void scan(void)
{
  
  if (!valid_diskette())
    invalid_diskette();
  
  state=HALT;
}
