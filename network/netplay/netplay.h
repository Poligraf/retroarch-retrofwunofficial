/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2017 - Daniel De Matteis
 *  Copyright (C) 2016-2017 - Gregor Richards
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

#ifndef __RARCH_NETPLAY_H
#define __RARCH_NETPLAY_H

#include <stdint.h>
#include <stddef.h>

#include <boolean.h>
#include <libretro.h>

#include "../../core.h"

typedef struct netplay netplay_t;

typedef struct mitm_server
{
   const char *name;
   const char *description;
} mitm_server_t;

static const mitm_server_t netplay_mitm_server_list[] = {
   { "nyc", "New York City, USA" },
   { "madrid", "Madrid, Spain" },
   { "montreal", "Montreal, Canada" },
   { "saopaulo", "Sao Paulo, Brazil" },
};

enum rarch_netplay_ctl_state
{
   RARCH_NETPLAY_CTL_NONE = 0,
   RARCH_NETPLAY_CTL_GAME_WATCH,
   RARCH_NETPLAY_CTL_POST_FRAME,
   RARCH_NETPLAY_CTL_PRE_FRAME,
   RARCH_NETPLAY_CTL_ENABLE_SERVER,
   RARCH_NETPLAY_CTL_ENABLE_CLIENT,
   RARCH_NETPLAY_CTL_DISABLE,
   RARCH_NETPLAY_CTL_IS_ENABLED,
   RARCH_NETPLAY_CTL_IS_REPLAYING,
   RARCH_NETPLAY_CTL_IS_SERVER,
   RARCH_NETPLAY_CTL_IS_CONNECTED,
   RARCH_NETPLAY_CTL_IS_DATA_INITED,
   RARCH_NETPLAY_CTL_PAUSE,
   RARCH_NETPLAY_CTL_UNPAUSE,
   RARCH_NETPLAY_CTL_LOAD_SAVESTATE,
   RARCH_NETPLAY_CTL_RESET,
   RARCH_NETPLAY_CTL_DISCONNECT,
   RARCH_NETPLAY_CTL_FINISHED_NAT_TRAVERSAL,
   RARCH_NETPLAY_CTL_DESYNC_PUSH,
   RARCH_NETPLAY_CTL_DESYNC_POP
};

/* Preferences for sharing digital devices */
enum rarch_netplay_share_digital_preference
{
   RARCH_NETPLAY_SHARE_DIGITAL_NO_SHARING = 0,
   RARCH_NETPLAY_SHARE_DIGITAL_NO_PREFERENCE,
   RARCH_NETPLAY_SHARE_DIGITAL_OR,
   RARCH_NETPLAY_SHARE_DIGITAL_XOR,
   RARCH_NETPLAY_SHARE_DIGITAL_VOTE,
   RARCH_NETPLAY_SHARE_DIGITAL_LAST
};

/* Preferences for sharing analog devices */
enum rarch_netplay_share_analog_preference
{
   RARCH_NETPLAY_SHARE_ANALOG_NO_SHARING = 0,
   RARCH_NETPLAY_SHARE_ANALOG_NO_PREFERENCE,
   RARCH_NETPLAY_SHARE_ANALOG_MAX,
   RARCH_NETPLAY_SHARE_ANALOG_AVERAGE,
   RARCH_NETPLAY_SHARE_ANALOG_LAST
};

bool netplay_driver_ctl(enum rarch_netplay_ctl_state state, void *data);

int netplay_rooms_parse(const char *buf);

struct netplay_room* netplay_room_get(int index);

int netplay_rooms_get_count(void);

void netplay_rooms_free(void);

#endif
