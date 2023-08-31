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
unsigned short current_size;
unsigned short current_free;
unsigned char selected_files_indexes[256];
unsigned char selected_files=0;
