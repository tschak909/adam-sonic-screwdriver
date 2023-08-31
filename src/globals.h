/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Globals
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#include "state.h"

typedef enum _filesystem
  {
    UNKNOWN_FILESYSTEM,
    EOS,
    CPM
  } FileSystem;

extern FileSystem current_filesystem;
extern char current_device;
extern char current_page;
extern State state;
extern unsigned char selected_files_indexes[256];
extern unsigned char selected_files;

#endif /* GLOBALS_H */
