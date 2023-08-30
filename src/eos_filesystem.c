/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose EOS Filesystem functions
 */

#include <eos.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "eos_filesystem.h"

bool volume_is_eos_filesystem(unsigned char dev)
{
  unsigned long block=0;

  // EOS Check Directory for File returns 0 on success here.
  return eos_check_directory_for_file("DIRECTORY\x03",&block,dev) == EOS_ERR_NONE;
}

bool entry_is_blocks_left(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_BLOCKS_LEFT) == ENTRY_ATTRIBUTE_BLOCKS_LEFT;
}

bool entry_is_exec_protect(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_EXEC_PROTECT) == ENTRY_ATTRIBUTE_EXEC_PROTECT;
}

bool entry_is_deleted(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_DELETED) == ENTRY_ATTRIBUTE_DELETED;
}

bool entry_is_system_file(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_SYSTEM_FILE) == ENTRY_ATTRIBUTE_SYSTEM_FILE;
}

bool entry_is_user_file(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_USER_FILE) == ENTRY_ATTRIBUTE_USER_FILE;
}

bool entry_is_read_protected(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_READ_PROTECT) == ENTRY_ATTRIBUTE_READ_PROTECT;
}

bool entry_is_write_protected(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_WRITE_PROTECT) == ENTRY_ATTRIBUTE_WRITE_PROTECT;
}

bool entry_is_locked(DirectoryEntry *d)
{
  return (d->attributes & ENTRY_ATTRIBUTE_LOCKED) == ENTRY_ATTRIBUTE_LOCKED;
}

bool directory_read(unsigned char dev, unsigned char *buf, unsigned short len, unsigned char *err, unsigned short *rlen)
{
  unsigned char f; // fileno
  
  if (!eos_open_file(0x05,"DIRECTORY\x03",1,&f))
    {
      *err = f;
      return false;
    }

  *rlen=eos_read_file(f,len,buf,err);
  
  eos_close_file(f);

  return err == 0;
}

void directory_filename(DirectoryEntry *d, char *fn, char *ft)
{
  for (int i=0;i<EOS_FILENAME_LEN;i++)
    {
      char c = d->filename[i];

      if (c==0x03)
	{
	  *ft=d->filename[i-1];
	  strncpy(fn,d->filename,i-1);
	  break;
	}
    }
}
