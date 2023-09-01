/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Globals
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>
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
extern unsigned short current_size;
extern unsigned long current_free;
extern unsigned short current_entry;
extern unsigned long current_block;
extern State state;
extern unsigned char selected_files_indexes[256];
extern unsigned char selected_files;
extern short entries_to_slots[32];
extern bool wildcard_mode;

#endif /* GLOBALS_H */
