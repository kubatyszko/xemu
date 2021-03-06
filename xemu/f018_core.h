/* Very primitive emulator of Commodore 65 + sub-set (!!) of Mega65 fetures.
   Copyright (C)2016 LGB (Gábor Lénárt) <lgblgblgb@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifndef __XEMU_F018_CORE_H_INCLUDED
#define __XEMU_F018_CORE_H_INCLUDED

typedef Uint8 (*dma_reader_cb_t)(int);
typedef void  (*dma_writer_cb_t)(int, Uint8);

extern Uint8 dma_status;
extern Uint8 dma_registers[16];

extern void  dma_write_reg ( int addr, Uint8 data );
extern Uint8 dma_read_reg  ( int reg );
extern void  dma_set_phys_io_offset ( int offs );
extern void  dma_init (
	dma_reader_cb_t set_source_mreader , dma_writer_cb_t set_source_mwriter , dma_reader_cb_t set_target_mreader , dma_writer_cb_t set_target_mwriter,
	dma_reader_cb_t set_source_ioreader, dma_writer_cb_t set_source_iowriter, dma_reader_cb_t set_target_ioreader, dma_writer_cb_t set_target_iowriter,
	dma_reader_cb_t set_list_reader
);
extern void  dma_reset     ( void );
extern void  dma_update    ( void );

/* Things should be provided by the emulator: */


/* Snapshot related part: */

#ifdef XEMU_SNAPSHOT_SUPPORT
#include "xemu/emutools_snapshot.h"
extern int dma_snapshot_load_state ( const struct xemu_snapshot_definition_st *def, struct xemu_snapshot_block_st *block );
extern int dma_snapshot_save_state ( const struct xemu_snapshot_definition_st *def );
#endif

#endif
