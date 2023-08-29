/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose EOS Filesystem functions
 */

#ifndef EOS_FILESYSTEM_H
#define EOS_FILESYSTEM_H

#include <eos.h>
#include <stdbool.h>

/**
 * @brief is filesystem in device dev an EOS filesystem?
 * @param dev the AdamNet device to check
 * @return true if an EOS filesystem, false if not.
 */
bool is_eos_filesystem(unsigned char dev);

#endif /* EOS_FILESYSTEM_H */
