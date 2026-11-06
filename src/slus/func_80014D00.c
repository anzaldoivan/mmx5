#include "types.h"

extern s32 CdControlB(s32, s32, u8*);
extern void SsSepClose(s32);
extern s32 SsSepOpenJ(u8*, s32, s32);
extern s8 func_80014464(void);
extern void* func_80066D98(void* func);
extern s8 D_80093E60[];
extern s8 D_80093E6C[];
extern u8 D_8009811C;
extern s32 D_800E5A18;
extern u8* D_800E5A1C;
extern u32 D_800E5A2C;
extern u8 D_800E5A3D;
extern u8* D_800E5BD8;

void func_80014D00(void) {
    s32 idx;
    s8* p;

    if (D_800E5A3D != 0) {
        D_800E5A3D = 0;
        D_800E5A1C = D_800E5BD8;
    }
    if (func_80014464() == -1) {
        func_80066D98(0);
        CdControlB(9, 0, 0);
        D_8009811C = 0x80;
        return;
    }
    if (D_800E5A18 == 0) {
        idx = (D_800E5A2C >> 8) & 0xFF;
        p = &D_80093E6C[idx];
        if (*p != -1) {
            SsSepClose(*p);
            *p = -1;
        }
        *p = SsSepOpenJ(D_800E5BD8, D_80093E60[idx], 3);
    }
}
