/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Edit Property
 */

#include <eos.h>
#include <msx.h>
#include <smartkeys.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "input.h"
#include "state.h"
#include "globals.h"
#include "directory.h"
#include "buffer.h"
#include "eos_filesystem.h"
#include "cursor.h"

void edit_property_date(void)
{
}

void edit_property_start_block(void)
{
}

void edit_property_allocated_blocks(void)
{
}

void edit_property_used_blocks(void)
{
}

void edit_property_last_block_bytes(void)
{
}

void edit_property_attribute_locked(void)
{
}

void edit_property_attribute_write_protected(void)
{
}

void edit_property_attribute_read_protected(void)
{
}

void edit_property_attribute_user_file(void)
{
}

void edit_property_attribute_system_file(void)
{
}

void edit_property_attribute_deleted(void)
{
}

void edit_property_attribute_exec_protected(void)
{
}

void edit_property_attribute_blocks_left_file(void)
{
}

void edit_property(void)
{
  while (state==EDIT_PROPERTY)
    {
      switch (propertiesField)
	{
	case PROPERTIES_DATE:
	  edit_property_date();
	  break;
	case PROPERTIES_START_BLOCK:
	  edit_property_start_block();
	  break;
	case PROPERTIES_ALLOCATED_BLOCKS:
	  edit_property_allocated_blocks();
	  break;
	case PROPERTIES_USED_BLOCKS:
	  edit_property_used_blocks();
	  break;
	case PROPERTIES_LAST_BLOCK_BYTES:
	  edit_property_last_block_bytes();
	  break;
	case PROPERTIES_ATTRIBUTE_LOCKED:
	  edit_property_attribute_locked();
	  break;
	case PROPERTIES_ATTRIBUTE_WRITE_PROTECTED:
	  edit_property_attribute_write_protected();
	  break; 
	case PROPERTIES_ATTRIBUTE_READ_PROTECTED:
	  edit_property_attribute_read_protected();
	  break;
	case PROPERTIES_ATTRIBUTE_USER_FILE:
	  edit_property_attribute_user_file();
	  break;
	case PROPERTIES_ATTRIBUTE_SYSTEM_FILE:
	  edit_property_attribute_system_file();
	  break;
	case PROPERTIES_ATTRIBUTE_DELETED:
	  edit_property_attribute_deleted();
	  break; 
	case PROPERTIES_ATTRIBUTE_EXEC_PROTECTED:
	  edit_property_attribute_exec_protected();
	  break;
	case PROPERTIES_ATTRIBUTE_BLOCKS_LEFT_FILE:
	  edit_property_attribute_blocks_left_file();
	  break; 
	}
    }
}
