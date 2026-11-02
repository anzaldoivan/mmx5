#include "types.h"

extern s32 CdSearchFile(s32* fp, u8* name);
extern int CdPosToInt(void* p);
extern s32 CdControl(s32, u8*, u8*);
extern s32 CdRead(s32, u32*, s32);
extern s32 CdReadSync(s32, u8*);
extern u8 D_80010004[];
extern u8 D_8006F3FC[][22];
extern s32 D_800E5C08[][2];

void func_80013EE8(void) {
    s32 file[6];
    u8 result[8];
    s32 src = 0x80105000;
    u8* res;
    s32 base;
    s32 i;

search:
    i = CdSearchFile(file, D_80010004);
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
    for (i = 0; i < 0xAC; i++) {
        D_800E5C08[i][0] = base + ((s32*)src)[i * 2];
        D_800E5C08[i][1] = ((s32*)src)[i * 2 + 1];
    }
    for (i = 0xAC; i < 0xAF; i++) {
        while (CdSearchFile(file, D_8006F3FC[i]) == 0) {
        }
        D_800E5C08[i][0] = CdPosToInt(file);
        D_800E5C08[i][1] = file[1];
        while (CdControl(9, 0, 0) == 0) {
        }
    }
}
