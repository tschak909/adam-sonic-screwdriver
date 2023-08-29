/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose EOS Filesystem functions
 */

#include <eos.h>
#include <stdbool.h>

bool is_eos_filesystem(unsigned char dev)
{
  unsigned long block=0;

  // EOS Check Directory for File returns 0 on success here.
  return eos_check_directory_for_file("DIRECTORY\x03",&block,dev) == EOS_ERR_NONE;
}
