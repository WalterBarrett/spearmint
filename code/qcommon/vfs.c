#ifndef _VFS_C_
#define _VFS_C_
#include "../qcommon/gameconfig.h"
#include "../qcommon/q_shared.h"

qboolean VFS_Initialized(vfsNum_t vfs);

static const char *defaultVfsNames[VFS_MAX] = {
	"invalid",
	"default",
	"ext1",
	"ext1",
	"ext2",
	"ext3",
	"ext4",
	"ext5",
	"ext6",
	"ext7",
	"ext8",
	"ext9",
	"ext10",
	"ext11",
	"ext12",
	"ext13",
	"ext14",
	"ext15"
};

const char *VFS_StringFromNum(vfsNum_t vfs)
{
	if (vfs >= VFS_INVALID && vfs < VFS_MAX)
	{
		if (!com_gameConfig.vfsNames[vfs][0]) {
			return defaultVfsNames[vfs];
		}
		return com_gameConfig.vfsNames[vfs];
	}
	return defaultVfsNames[VFS_INVALID];
}

extern int Q_stricmp(const char *s1, const char *s2);

vfsNum_t VFS_NumFromString(char* vfsStr)
{
	vfsNum_t vfs;
	for (vfs = VFS_INVALID; vfs < VFS_MAX; vfs++) {
		if (!Q_stricmp(VFS_StringFromNum(vfs), vfsStr)) {
			return vfs;
		}
	}
	for (vfs = VFS_INVALID; vfs < VFS_MAX; vfs++) {
		if (!Q_stricmp(defaultVfsNames[vfs], vfsStr)) {
			return vfs;
		}
	}
	return VFS_INVALID;
}

static const char *blankString = "";

const char *VFS_Lang_ToVFSName(vfsNum_t vfs) {
	static int curIter = -1;
	static char tmpString[4][MAX_QPATH * 2];
	if (vfs == VFS_DEFAULT) {
		return blankString;
	} else {
		curIter++;
		curIter = curIter % ARRAY_LEN(tmpString);
		if (vfs <= VFS_INVALID || vfs >= VFS_MAX) {
			Com_sprintf(tmpString[curIter], sizeof(tmpString[0]), " to invalid VFS #%i", vfs);
		} else if (!VFS_Initialized(vfs)) {
			Com_sprintf(tmpString[curIter], sizeof(tmpString[0]), " to uninitialized VFS #%i '%s'", vfs, VFS_StringFromNum(vfs));
		} else {
			Com_sprintf(tmpString[curIter], sizeof(tmpString[0]), " to VFS #%i '%s'", vfs, VFS_StringFromNum(vfs));
		}
		return tmpString[curIter];
	}
}

const char *VFS_Lang_FromVFSName(vfsNum_t vfs) {
	static int curIter = -1;
	static char tmpString[4][MAX_QPATH * 2];
	if (vfs == VFS_DEFAULT) {
		return blankString;
	} else {
		curIter++;
		curIter = curIter % ARRAY_LEN(tmpString);
		if (vfs <= VFS_INVALID || vfs >= VFS_MAX) {
			Com_sprintf(tmpString[curIter], sizeof(tmpString[0]), " from invalid VFS #%i", vfs);
		} else if (!VFS_Initialized(vfs)) {
			Com_sprintf(tmpString[curIter], sizeof(tmpString[0]), " from uninitialized VFS #%i '%s'", vfs, VFS_StringFromNum(vfs));
		} else {
			Com_sprintf(tmpString[curIter], sizeof(tmpString[0]), " from VFS #%i '%s'", vfs, VFS_StringFromNum(vfs));
		}
		return tmpString[curIter];
	}
}
#endif
