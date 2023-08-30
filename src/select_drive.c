/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Select drive
 */

#include <stdlib.h>
#include <smartkeys.h>
#include "state.h"
#include "directory.h"

extern State state;

void select_drive(void)
{
  directory_bkg();
  smartkeys_display("  \x1f\x1f\x1f\x1f""DEVICE\n     4"," \x1f\x1f""DEVICE\n   \x1f\x1f""5"," \x1f\x1f""DEVICE\n   \x1f\x1f""6"," \x1f\x1f""DEVICE\n   \x1f\x1f""7"," \x1f\x1f""DEVICE\n   \x1f\x1f""8"," \x1f\x1f\x1f""DEVICE\n   18");
  
  state=HALT;
}
