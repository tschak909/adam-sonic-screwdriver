/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Set label for format
 */

#include <eos.h>
#include <video/tms99x8.h>
#include <smartkeys.h>
#include <conio.h>
#include "directory.h"
#include "state.h"
#include "rleunpack.h"
#include "eos_filesystem.h"
#include "cpm_filesystem.h"
#include "buffer.h"
#include "globals.h"
#include "input.h"
#include "cursor.h"

void format_label(void)
{
  bool keyVI=false;

  selector(false);
  cursor(false);

  directory_bkg();
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,"  ABORT");
  smartkeys_status("   ENTER A VOLUME LABEL.");
  
  vdp_color(1,15,7);  
  input_line(3,1,0,current_label,12,keyVI);

  if (keyVI)
    state=MENU_DRIVE;
  else
    state=FORMAT_MAKE_FILESYSTEM;  
}
