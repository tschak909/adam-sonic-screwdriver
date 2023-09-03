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

typedef enum _propertiesField
  {
    PROPERTIES_DATE,
    PROPERTIES_START_BLOCK,
    PROPERTIES_ALLOCATED_BLOCKS,
    PROPERTIES_USED_BLOCKS,
    PROPERTIES_LAST_BLOCK_BYTES,
    PROPERTIES_ATTRIBUTE_LOCKED,
    PROPERTIES_ATTRIBUTE_WRITE_PROTECTED,
    PROPERTIES_ATTRIBUTE_READ_PROTECTED,
    PROPERTIES_ATTRIBUTE_USER_FILE,
    PROPERTIES_ATTRIBUTE_SYSTEM_FILE,
    PROPERTIES_ATTRIBUTE_DELETED,
    PROPERTIES_ATTRIBUTE_EXEC_PROTECTED,
    PROPERTIES_ATTRIBUTE_BLOCKS_LEFT_FILE,
  } PropertiesField;


extern FileSystem current_filesystem;
extern char current_device;
extern char current_page;
extern unsigned short current_size;
extern unsigned long current_free;
extern unsigned short current_entry;
extern unsigned long current_block;
extern int current_pos;
extern unsigned char current_dirsize;
extern unsigned char current_label[13];
extern unsigned char properties_pos;
extern PropertiesField propertiesField;
extern State state;
extern unsigned char selected_files_indexes[256];
extern unsigned char selected_files;
extern short entries_to_slots[32];
extern bool wildcard_mode;
extern unsigned char volume_map_page;

#endif /* GLOBALS_H */
