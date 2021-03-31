/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2015-2018 - Andre Leiradella
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __RARCH_CHEEVOS_MEMORY_H
#define __RARCH_CHEEVOS_MEMORY_H

#include <stdint.h>
#include <stdlib.h>
#include <boolean.h>

#include <retro_common_api.h>

RETRO_BEGIN_DECLS

#define MAX_MEMORY_REGIONS 32

typedef struct
{
   uint8_t* data[MAX_MEMORY_REGIONS];
   size_t size[MAX_MEMORY_REGIONS];
   size_t total_size;
   unsigned count;
} rcheevos_memory_regions_t;

bool rcheevos_memory_init(rcheevos_memory_regions_t* regions, int console);
void rcheevos_memory_destroy(rcheevos_memory_regions_t* regions);

uint8_t* rcheevos_memory_find(const rcheevos_memory_regions_t* regions,
      unsigned address);

RETRO_END_DECLS

#endif
