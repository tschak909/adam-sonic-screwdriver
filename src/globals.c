/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Globals
 */

#include "globals.h"

char current_device=5;
FileSystem current_filesystem=UNKNOWN_FILESYSTEM;
char current_page=0;
unsigned short current_size=0;
unsigned long current_free=0;
unsigned short current_entry=0;
unsigned long current_block=0UL;
int current_pos=0;
unsigned char properties_pos=0;
unsigned char selected_files_indexes[256];
unsigned char selected_files=0;
short entries_to_slots[32];
bool wildcard_mode=false;
PropertiesField propertiesField=PROPERTIES_DATE;
unsigned char volume_map_page=0;
