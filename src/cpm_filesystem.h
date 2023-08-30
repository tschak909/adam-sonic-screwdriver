/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose CP/M Filesystem functions
 */

#ifndef CPM_FILESYSTEM_H
#define CPM_FILESYSTEM_H

#include <stdbool.h>

typedef struct _cpmDirectoryEntry
{
  unsigned char user;
  char filename[8];
  char extension[3];
  unsigned char extent_number;
  unsigned char s1;
  unsigned char s2;
  unsigned char record_count;
  unsigned char allocated_sectors[16];
} CpmDirectoryEntry;

/**
 * @brief is filesystem in device dev a CP/M filesystem?
 * @param dev the AdamNet device to check
 * @return true if an EOS filesystem, false if not.
 */
bool volume_is_cpm_filesystem(unsigned char dev);

/**
 * @brief is character a valid filename character
 * @param c the char to check
 * @return true if valid, false if not.
 */
bool valid_cpm_filename_character(char c);

/**
 * @brief read CP/M directory sectors into buffer
 * @param dev The AdamNet device to read from
 * @return true if successfully read, false if not.
 */
bool directory_read_cpm(unsigned char dev);

#endif /* CPM_FILESYSTEM_H */
