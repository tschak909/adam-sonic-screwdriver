/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose EOS Filesystem functions
 */

#ifndef EOS_FILESYSTEM_H
#define EOS_FILESYSTEM_H

#include <eos.h>
#include <stdbool.h>

#define ENTRY_ATTRIBUTE_BLOCKS_LEFT 0x01
#define ENTRY_ATTRIBUTE_EXEC_PROTECT 0x02
#define ENTRY_ATTRIBUTE_DELETED 0x04
#define ENTRY_ATTRIBUTE_SYSTEM_FILE 0x08
#define ENTRY_ATTRIBUTE_USER_FILE 0x10
#define ENTRY_ATTRIBUTE_READ_PROTECT 0x20
#define ENTRY_ATTRIBUTE_WRITE_PROTECT 0x40
#define ENTRY_ATTRIBUTE_LOCKED 0x80

/**
 * @brief is filesystem in device dev an EOS filesystem?
 * @param dev the AdamNet device to check
 * @return true if an EOS filesystem, false if not.
 */
bool volume_is_eos_filesystem(unsigned char dev);

/**
 * @brief is the entry the blocks left file?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_blocks_left(DirectoryEntry *d);

/**
 * @brief is the entry protected from execution?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_exec_protect(DirectoryEntry *d);

/**
 * @brief is the entry deleted?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_deleted(DirectoryEntry *d);

/**
 * @brief is the entry a system file?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_system_file(DirectoryEntry *d);

/**
 * @brief is the entry a normal user file?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_user_file(DirectoryEntry *d);

/**
 * @brief is the entry read protected?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_read_protected(DirectoryEntry *d);

/**
 * @brief is the entry write protected?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_write_protected(DirectoryEntry *d);

/**
 * @brief is the entry locked?
 * @param pointer to the DirectoryEntry
 * @return true or false
 */
bool entry_is_locked(DirectoryEntry *d);

/**
 * @brief read directory file into buffer
 * @param dev AdamNet Device ID
 * @param buf The target buffer, must be large enough
 * @param len The target buffer length
 * @param err Put error code in this variable
 * @param rlen Put received # of bytes in this variable
 */
bool directory_read_eos(unsigned char dev, unsigned char *buf, unsigned short len, unsigned char *err, unsigned short *rlen);

/**
 * @brief Return filename and file type for directory entry
 * @param d The directory entry
 * @param fn pointer to a char array for filename (minimum, 11 chars)
 * @param ft pointer to a single char for the file type
 */
void directory_filename(DirectoryEntry *d, char *fn, char *ft);

#endif /* EOS_FILESYSTEM_H */
