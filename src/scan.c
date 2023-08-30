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
#include <stdbool.h>
#include "globals.h"
#include "scan.h"
#include "state.h"

bool valid_diskette(void)
{
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
