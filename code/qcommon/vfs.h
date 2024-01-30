#ifndef _VFS_H_
#define _VFS_H_
typedef enum {
	VFS_INVALID,
	VFS_DEFAULT,
	VFS_EXT0,
	VFS_EXT1,
	VFS_EXT2,
	VFS_EXT3,
	VFS_EXT4,
	VFS_EXT5,
	VFS_EXT6,
	VFS_EXT7,
	VFS_EXT8,
	VFS_EXT9,
	VFS_EXT10,
	VFS_EXT11,
	VFS_EXT12,
	VFS_EXT13,
	VFS_EXT14,
	VFS_EXT15,
	VFS_MAX,
} vfsNum_t;

extern const char *VFS_StringFromNum(vfsNum_t vfs);
extern vfsNum_t VFS_NumFromString(char* vfsStr);
extern const char *VFS_Lang_ToVFSName(vfsNum_t vfs);
extern const char *VFS_Lang_FromVFSName(vfsNum_t vfs);
#endif
