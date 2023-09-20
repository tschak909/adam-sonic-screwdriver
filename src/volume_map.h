/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Volume Map
 */

#ifndef VOLUME_MAP_H
#define VOLUME_MAP_H

void volume_map(void);
void volume_map_bad_blocks(void);
void volume_map_cursor_up(void);
void volume_map_cursor_right(void);
void volume_map_cursor_down(void);
void volume_map_cursor_left(void);
void volume_map_cursor_home(void);
void volume_map_view_block(void);

#endif /* VOLUME_MAP_H */
