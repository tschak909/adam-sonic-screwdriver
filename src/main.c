/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Main entrypoint
 */

#include <smartkeys.h>
#include <stdbool.h>
#include "state.h"
#include "splash.h"
#include "scan.h"
#include "select_drive.h"
#include "directory.h"
#include "hex_view.h"
#include "halt.h"
#include "globals.h"
#include "menu_main.h"
#include "menu_file.h"
#include "menu_drive.h"
#include "properties.h"
#include "volume_map.h"
#include "menu_map.h"
#include "menu_properties.h"
#include "retension.h"
#include "menu_format_type.h"
#include "menu_format_type_num_blocks.h"
#include "format_label.h"
#include "format_confirm.h"
#include "format.h"
#include "format_error.h"
#include "format_make_filesystem.h"
#include "format_make_filesystem_error.h"
#include "menu_check_for_bad_blocks.h"
#include "check_for_bad_blocks.h"
#include "check_for_bad_blocks_retry.h"
#include "test_harness.h"

State state=SCAN;

void main(void)
{
  // Set current device to boot device
  current_device = (*(unsigned char *)0xFD6F);

  smartkeys_sound_init();
  
  while(true)
    {
      switch(state)
	{
	case SPLASH:
	  splash();
	  break;
	case SCAN:
	  scan();
	  break;
	case SELECT_DRIVE:
	  select_drive();
	  break;
	case DIRECTORY:
	  directory();
	  break;
	case MENU_MAIN:
	  menu_main();
	  break;
	case MENU_FILE:
	  menu_file();
	  break;
	case MENU_DRIVE:
	  menu_drive();
	  break;
	case HEX_VIEW:
	  hex_view();
	  break;
	case PROPERTIES:
	  properties();
	  break;
	case MENU_PROPERTIES:
	  menu_properties();
	  break;
	case VOLUME_MAP:
	  volume_map();
	  break;
	case VOLUME_MAP_BAD_BLOCKS:
	  volume_map_bad_blocks();
	  break;
	case MENU_MAP:
	  menu_map();
	  break;
	case RETENSION:
	  retension();
	  break;
	case FORMAT_LABEL:
	  format_label();
	  break;
	case FORMAT_CONFIRM:
	  format_confirm();
	  break;
	case FORMAT:
	  format();
	  break;
	case FORMAT_ERROR:
	  format_error();
	  break;
	case MENU_CHECK_FOR_BAD_BLOCKS:
	  menu_check_for_bad_blocks();
	  break;
	case CHECK_FOR_BAD_BLOCKS:
	  check_for_bad_blocks();
	  break;
	case CHECK_FOR_BAD_BLOCKS_RETRY:
	  check_for_bad_blocks_retry();
	  break;
	case MENU_FORMAT_TYPE:
	  menu_format_type();
	  break;
	case MENU_FORMAT_TYPE_NUM_BLOCKS:
	  menu_format_type_num_blocks();
	  break;
	case FORMAT_MAKE_FILESYSTEM:
	  format_make_filesystem();
	  break;
	case FORMAT_MAKE_FILESYSTEM_ERROR:
	  format_make_filesystem_error();
	  break;
	case TEST_HARNESS:
	  test_harness();
	  break;
	case HALT:
	  halt();
	  break;
	}
    }
}
