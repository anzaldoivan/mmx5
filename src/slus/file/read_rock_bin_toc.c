#include "types.h"

extern s32 CdSearchFile(s32* fp, u8* name);
extern int CdPosToInt(void* p);
extern s32 CdControl(s32, u8*, u8*);
extern s32 CdRead(s32, u32*, s32);
extern s32 CdReadSync(s32, u8*);
extern u8 g_rock_x5_bin_path[];
extern PairFB4BC D_800E6188[];

void read_rock_bin_toc(void) {
    s32 file[6];
    u8 result[8];
    s32 src = 0x80105000;
    u8* res;
    s32 base;
    s32 i;

search: // !FAKE: label kept for the matching register order
    i = CdSearchFile(file, g_rock_x5_bin_path);
    res = result;
    if (i == 0) {
        goto search; // !FAKE: goto kept for the matching register order
    }
    base = CdPosToInt(file);
    CdControl(2, (u8*)file, 0);
    CdRead(1, (u32*)src, 0x80);
    CdReadSync(0, res);
    while (CdControl(9, 0, 0) == 0) {
    }
    for (i = 0; i < 59; i++) {
        D_800E6188[i].x = base + ((s32*)src)[i * 2];
        D_800E6188[i].y = ((s32*)src)[i * 2 + 1];
    }
}
