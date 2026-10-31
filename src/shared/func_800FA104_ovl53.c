/* Shared body (DK-5), from the banked draft of func_800FA104_ovl53 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern u8* func_8002D53C(void);
extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_8009A1F8[];
extern u8 D_800FAD9C_ovl53[];
extern u8 D_800FAF9C_ovl53[];
extern u8 D_800FB19C_ovl53[];
extern u8 D_800FB39C_ovl53[];

void DEDUP_NAME(u8* arg0) {
    u8* p;
    u8* o;

    if (D_80091C44 == 0) {
        if (++*(s16*)(arg0 + 4) > 0x3C) {
            p = D_8009A1F8;
            *(s16*)(p + 0xA) = 0;
            *(s16*)(p + 0xE) = 0x100;
            p[0x3] = 1;
            p[0x4C] = 1;
            *(s16*)(p + 0x5E) = 0;
            *(s16*)(p + 0x62) = 0x100;
            p[0x57] = 1;
            p[0xA0] = 1;
            func_8002C3CC(D_800FAF9C_ovl53, D_800FAD9C_ovl53, 0x100, 0x3C,
                          0x3C);
            func_8002C338(0x60, D_800FAF9C_ovl53, 0x10);
            func_8002C3CC(D_800FB39C_ovl53, D_800FB19C_ovl53, 0x100, 0, 0x3C);
            func_8002C338(0x70, D_800FB39C_ovl53, 0x10);
            o = func_8002D53C();
            if (o != 0) {
                o[0] = 1;
                o[1] = 9;
                o[0x36] = 0x11;
                *(s16*)(o + 0x34) = 0x7FFF;
                o[2] = 1;
                *(s32*)(o + 0x38) = 0x28;
            }
            *(s16*)(arg0 + 4) = 1;
            arg0[1]++;
            D_80093E66 = 0;
            D_8009A42C = 0;
            D_800D50DC = 0;
            func_8002C1C8();
        }
    }
}
