/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2015-2016 - Andre Leiradella
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

#include <file/file_path.h>

#include "../file_path_special.h"
#include "../configuration.h"
#include "../gfx/gfx_display.h"

#include "badges.h"

#ifdef HAVE_MENU

#define CHEEVOS_MENU_BADGE_LIMIT 256
/* TODO/FIXME - public global variables */
static uintptr_t cheevos_badge_menu_texture_list[CHEEVOS_MENU_BADGE_LIMIT] = { 0 };

void cheevos_reset_menu_badges(void)
{
   int index;
   for (index = 0; index < CHEEVOS_MENU_BADGE_LIMIT; ++index)
   {
      if (cheevos_badge_menu_texture_list[index])
         video_driver_texture_unload(&cheevos_badge_menu_texture_list[index]);
   }

   memset(&cheevos_badge_menu_texture_list, 0,
         sizeof(cheevos_badge_menu_texture_list));
}

void cheevos_set_menu_badge(int index, const char *badge, bool locked)
{
   settings_t *settings = config_get_ptr();

   if (index >= CHEEVOS_MENU_BADGE_LIMIT)
      return;

   if (!settings || !settings->bools.cheevos_badges_enable)
      cheevos_badge_menu_texture_list[index] = 0;
   else
      cheevos_badge_menu_texture_list[index] = 
         cheevos_get_badge_texture(badge, locked);
}

uintptr_t cheevos_get_menu_badge_texture(int index)
{
   if (index < CHEEVOS_MENU_BADGE_LIMIT)
      return cheevos_badge_menu_texture_list[index];

   return 0;
}

#endif

uintptr_t cheevos_get_badge_texture(const char *badge, bool locked)
{
   char badge_file[24];
   char fullpath[PATH_MAX_LENGTH];
   uintptr_t tex = 0;

   if (!badge)
      return 0;

   fullpath[0]   = badge_file[0] = '\0';

   strlcpy(badge_file, badge, sizeof(badge_file));
   if (locked)
      strlcat(badge_file, "_lock", sizeof(badge_file));
   strlcat(badge_file, FILE_PATH_PNG_EXTENSION, sizeof(badge_file));

   fill_pathname_application_special(fullpath, sizeof(fullpath),
      APPLICATION_SPECIAL_DIRECTORY_THUMBNAILS_CHEEVOS_BADGES);

   if (!gfx_display_reset_textures_list(badge_file, fullpath,
      &tex, TEXTURE_FILTER_MIPMAP_LINEAR, NULL, NULL))
      tex = 0;

   return tex;
}
