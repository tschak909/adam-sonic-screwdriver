/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Format
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

#define FORMAT_CMD_BLOCK 0xFACEUL

void format(void)
{
  char tmp[64];

  snprintf(tmp,sizeof(tmp),"   FORMATTING MEDIA\n   IN DRIVE %02x",current_device);
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status(tmp);

  if (eos_read_block(current_device,FORMAT_CMD_BLOCK,buffer) == 0x16) // Format error
    state=FORMAT_ERROR;
  else
    state=MENU_FORMAT_TYPE;
}
