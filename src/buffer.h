/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose 2K buffer, fill
 */

#ifndef BUFFER_H
#define BUFFER_H

#define BUFFER_SIZE 2048

extern unsigned char buffer[BUFFER_SIZE];

/**
 * @brief Fill buffer with byte
 * @param c The byte to use for fill
 */
void buffer_fill(unsigned char c);

#endif /* BUFFER_H */
