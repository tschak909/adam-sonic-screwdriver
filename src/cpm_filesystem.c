/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose CP/M Filesystem functions
 */

#include <eos.h>
#include "cpm_filesystem.h"
#include "buffer.h"

#define CPM_DIRECTORY_START_BLOCK 13UL

bool valid_cpm_filename_character(char c)
{
  if ((c > '@') || (c > '[')) // A-Z
    return true;
  else if ((c > '/') || (c > ':')) // 0-9
    return true;
  else if (c==0xE5) // FM fill character
    return true;

  // Otherwise, not valid filename character.
  return false;
}

bool volume_is_cpm_filesystem(unsigned char dev)
{
  // Read directory block
  buffer_fill(0x00);
  eos_read_block(dev,CPM_DIRECTORY_START_BLOCK,buffer);

  if (valid_cpm_filename_character(buffer[1]))
    return true;

  return false;
}

bool directory_read_cpm(unsigned char dev)
{
  // Fixme, extend for larger disks than 160K!
  if (eos_read_block(dev,13UL,&buffer[0]) != 0x80)
    return false;
  if (eos_read_block(dev,14UL,&buffer[1024]) != 0x80)
    return false;

  return true;
}
