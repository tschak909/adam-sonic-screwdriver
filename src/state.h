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
    VOLUME_MAP,
    MENU_MAP,
    HALT
  } State;

#endif /* STATE_H */
