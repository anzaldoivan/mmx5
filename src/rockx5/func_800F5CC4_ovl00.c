#include "types.h"

extern void func_8004FD90(u8*, s32, s32, s32);
extern s32 func_8002DF78(void);
extern void func_80016490(s32, s32, void*);
extern s32 D_8009A420;
extern s32 D_800FB2A4_ovl00[];

void func_800F5CC4_ovl00(u8* a0) {
    if (--*(s32*)(a0 + 0x7C) != 0) {
        if ((D_8009A420 & 7) == 0) {
            func_8004FD90(a0, 1, 0x1F, 0x1F);
        }
        if ((D_8009A420 & 0xF) == 0) {
            func_80016490(0, D_800FB2A4_ovl00[func_8002DF78() & 3], a0);
        }
    } else {
        a0[4] = 3;
        a0[6] = 0;
    }
}
