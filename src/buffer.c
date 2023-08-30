/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose 2K buffer, fill
 */

#include <string.h>
#include "buffer.h"

unsigned char buffer[BUFFER_SIZE];

void buffer_fill(unsigned char c)
{
  memset(buffer,c,BUFFER_SIZE);
}
