/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose State typedefs
 */

#ifndef STATE_H
#define STATE_H

typedef enum _state
  {
    SPLASH,
    SCAN,
    SELECT_DRIVE,
    DIRECTORY,
    HEX_VIEW,
    MENU_MAIN,
    MENU_FILE,
    MENU_DRIVE,
    PROPERTIES,
    MENU_PROPERTIES,
    EDIT_PROPERTY,
    VOLUME_MAP,
    VOLUME_MAP_BAD_BLOCKS,
    MENU_MAP,
    RETENSION,
    FORMAT_CONFIRM,
    FORMAT,
    FORMAT_ERROR,
    CHECK_FOR_BAD_BLOCKS,
    CHECK_FOR_BAD_BLOCKS_RETRY,
    MENU_FORMAT_TYPE,
    FORMAT_MAKE_FILESYSTEM,
    TEST_HARNESS,
    HALT
  } State;

#endif /* STATE_H */
