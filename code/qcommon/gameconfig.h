/*
===========================================================================
Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company.

This file is part of Spearmint Source Code.

Spearmint Source Code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 3 of the License,
or (at your option) any later version.

Spearmint Source Code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Spearmint Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, Spearmint Source Code is also subject to certain additional terms.
You should have received a copy of these additional terms immediately following
the terms and conditions of the GNU General Public License.  If not, please
request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional
terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc.,
Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/
// gameconfig.h -- Game config, loaded from mint-game.settings (see GAMESETTINGS define)
#ifndef _GAMECONFIG_H_
#define _GAMECONFIG_H_

#include "../qcommon/q_shared.h"
#include "../qcommon/vfs.h"

#define MAX_GAMEDIRS 16 // max gamedirs a mod can have per VFS
#define MAX_LOADINGSCREENS	200

typedef struct loadingScreen_s {
	char	shaderName[MAX_QPATH];
	float	aspect;
	vec3_t	color;
} loadingScreen_t;

typedef struct {
	char	vfsDirs[VFS_MAX][MAX_GAMEDIRS][MAX_QPATH];
	int		numVfsDirs[VFS_MAX];
	char	vfsNames[VFS_MAX][MAX_QPATH];
	int		vfsCount;

#ifndef DEDICATED
	char	defaultSound[MAX_QPATH];

	loadingScreen_t	loadingScreens[MAX_LOADINGSCREENS];
	int			numLoadingScreens;
#endif
} gameConfig_t;

extern gameConfig_t com_gameConfig;
#endif
