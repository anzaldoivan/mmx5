#include "types.h"

extern s32 func_80066D78(s32, s32);
extern s32 CdControlB(s32, s32, u8*);
extern s32 SsVabClose(s32);
extern void* func_80066D98(void* func);
extern void func_80014944(void);
extern void func_80014A30(void);

extern u8 D_8009811C;
extern u32 D_800E5BF0;
extern u8 D_800E5BEA;
extern u8 D_800E5A58[][12];
extern u8 D_800E5BE9;
extern s32 D_800E5BEC;
extern u8 D_80091D50;
extern u8 D_800E5209;
extern u8 D_800E5208;
extern s16 D_800E5A44;
extern s16 D_800E5A46;
extern s8 D_80093E60[];
extern s32 D_800E5BE0;
extern s32 D_800E5BE4;
extern s32 D_800E5BD8;
extern s32 D_800D1F38;
extern s32 D_800C9314;
extern s32 D_800BE9A8;
extern s32 D_8009E790;
extern s32 D_800E5C08[][2];
extern s32 D_800E5A30;
extern s32 D_800E5A18;
extern s32 D_800E5A24;

void func_80014684(s32 idx, u8 mode, s32 arg2) {
    u8 i;
    s32* p;

    if (func_80066D78(1, 0) != 0) {
        CdControlB(9, 0, 0);
    }
    if (D_8009811C != 0x80) {
        D_800E5BF0 = 0;
    }
    D_8009811C = 0;
    D_800E5BE9 = idx;
    D_800E5BEA = mode;
    D_800E5BEC = arg2;
    D_80091D50 = 0;
    D_800E5209 = 0;
    D_800E5208 = 0;
    D_800E5A44 = 0;
    D_800E5A46 = 0;
    for (i = 0; i < 32; i++) {
        D_800E5A58[i][0] = 0;
    }
    switch (D_800E5BEA) {
    case 0:
        D_800E5BE0 = 0x80105000;
        D_800E5BE4 = 0x1010;
        for (i = 0; i < 6; i++) {
            if (D_80093E60[i] != -1) {
                SsVabClose(D_80093E60[i]);
                D_80093E60[i] = -1;
            }
        }
        break;
    case 1:
        D_800E5BE0 = D_800E5BD8;
        break;
    case 2:
        D_800E5BE0 = arg2;
        break;
    case 3:
        D_800E5BE0 = D_800D1F38;
        D_800E5BE4 = D_800C9314;
        for (i = 2; i < 6; i++) {
            if (i != 3) {
                if (D_80093E60[i] != -1) {
                    SsVabClose(D_80093E60[i]);
                    D_80093E60[i] = -1;
                }
            }
        }
        break;
    case 4:
        D_800E5BE4 = arg2;
        D_800E5BE0 = D_800BE9A8;
        if (D_80093E60[2] != -1) {
            SsVabClose(D_80093E60[2]);
            D_80093E60[2] = -1;
        } else {
            D_800E5BE4 = D_8009E790;
        }
        break;
    }
    p = D_800E5C08[idx];
    D_800E5A30 = 1;
    D_800E5A18 = p[1];
    D_800E5A24 = p[0];
    func_80066D98(func_80014A30);
    func_80014944();
}
