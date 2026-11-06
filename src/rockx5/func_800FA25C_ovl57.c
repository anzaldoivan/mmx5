#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern s32 func_8002C338(s32, void*, s32);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern u8 D_800FAFE8_ovl57[];
extern u8 D_800FB1E8_ovl57[];
extern u8 D_800FB3E8_ovl57[];
extern u8 D_800FB5E8_ovl57[];

void func_800FA25C_ovl57(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        func_8002C3CC(D_800FB1E8_ovl57, D_800FAFE8_ovl57, 0x100,
                      0x3C - *(s16*)(arg0 + 4), 0x3C);
        func_8002C338(0x50, D_800FB1E8_ovl57, 0x10);
        func_8002C3CC(D_800FB5E8_ovl57, D_800FB3E8_ovl57, 0x100,
                      0x3C - *(s16*)(arg0 + 4), 0x3C);
        func_8002C338(0x90, D_800FB5E8_ovl57, 0x10);
        p = D_8009A1F8;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0x20;
        *(s16*)(p + 0x62) = 0;
        p[0xA0] = 1;
        func_80016490(2, 0x5A, 0);
        arg0[1]++;
    }
}
