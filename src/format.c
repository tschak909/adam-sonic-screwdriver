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
    {
      state=FORMAT_ERROR;
      return;
    }

  // Write a default boot block that properly sets the VDP interrupt, and goes into SmartWriter.

  buffer_fill(0x00);

  buffer[0]=0x01;    // ld bc,$45ed
  buffer[1]=0xed;    
  buffer[2]=0x45;
  buffer[3]=0xed;    // ld ($0066),bc
  buffer[4]=0x43;   
  buffer[5]=0x66;
  buffer[6]=0x00;
  buffer[7]=0xc3;    // jp $FCE7
  buffer[8]=0xe7;
  buffer[9]=0xfc;
  buffer[10]=0xed;   // retn
  buffer[11]=0x45;

  eos_write_block(current_device,0x00UL,buffer);
  eos_write_block(current_device,0x00UL,buffer);

  // Continue to selecting format type
  state=MENU_FORMAT_TYPE;
}
