#include "types.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001C4C0.c, AGPL-3.0 (THIRD_PARTY.md). */

extern const MemcardPath D_800100B4;
extern u8 D_800E81DE;
s32 func_8001D7E8(s32);
void memset(void* dst, s32 c, s32 n);
u8* strcpy(u8* dst, u8* src);
void* nextfile(void* dir);
void* firstfile(u8* name, void* dir);

static inline void func_8001D6BC_name(u8* path, u8* name) {
    *(MemcardPath*)path = D_800100B4;
    memset(path + 6, 0, 0x1A);
    strcpy(path + 5, name);
}

s32 memcard_list_files(s32 arg0, u8* arg1, u8* arg2) {
    s32 dir[10];
    u8 path[32];
    s32 ret;
    s32 size;
    s32* sizes;

    func_8001D6BC_name(path, arg2);
    arg1[0x14A] = 0;
    *(s32*)(arg1 + 0x14C) = 0;
    path[2] += arg0;
    if (firstfile(path, dir) == dir) {
        sizes = (s32*)(arg1 + 0x150);
        do {
            strcpy(arg1 + arg1[0x14A] * 0x16, (u8*)dir);
            size = dir[6];
            *(s32*)((u8*)sizes + (arg1[0x14A] << 2)) = size;
            *(s32*)(arg1 + 0x14C) += size;
            arg1[0x14A]++;
        } while (nextfile(dir) == dir);
        ret = 0;
    } else {
        ret = 1;
    }
    if (ret == 0) {
        return 0;
    }
    return func_8001D7E8(D_800E81DE);
}

#include "shared/func_8001D7E8.c"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001C6C0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/memcard.c:func_8001CE84, AGPL-3.0; proven shared with X6 by exact signature e642975dc52e (see THIRD_PARTY.md). */

extern long format(u8*);
extern const MemcardPath D_800100B4;

s32 memcard_format(s32 device_num) {
    MemcardPath buf = D_800100B4;

    buf.path[2] += device_num;
    return format(buf.path) ^ 1;
}
