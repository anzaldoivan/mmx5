#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern void func_80016490(s32, s32, void*);
extern void func_800FD050_ovl30(s32, void*, u8*, s32);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern s8 D_800D1C00[];
extern u8 D_8009A0A0[];
extern u16 D_800FDC80_ovl30[];
extern u16 D_800FDC44_ovl30[];
extern u8 D_800FDBB4_ovl30[];

void func_800FB024_ovl30(u8* obj) {
    s32 off;
    u8* g;
    u8* h;

    off = 0x1F0;
    if (D_800D1C00[0xC] != 0xC) {
        off = 0x24F0;
    }
    if (*(s16*)(obj + 0x7E) >= 0x20) {
        g = D_8009A0A0;
        *(s16*)(obj + 0xA) =
            D_800FDC80_ovl30[D_800FDC44_ovl30[(*(s16*)(g + 0xA) - off) / 16]];
        if (*(s16*)(g + 0xA) < *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        h = D_8009A0A0;
        switch (D_800FDC44_ovl30[(*(s16*)(h + 0xA) - off) / 16]) {
        case 1:
        case 3:
        case 5:
            obj[0x15] = 0x40;
            func_800171E8(obj, 7);
            if (D_800D1C00[0xC] != 0xC) {
                if (func_8002DF78() & 1) {
                    *(s16*)(obj + 0xE) = 0x158;
                } else {
                    *(s16*)(obj + 0xE) = 0x170;
                }
            } else {
                if (func_8002DF78() & 1) {
                    *(s16*)(obj + 0xE) = 0x78;
                } else {
                    *(s16*)(obj + 0xE) = 0x90;
                }
            }
            obj[6] = 4;
            func_80016490(2, 0xC, obj);
            func_800FD050_ovl30(0, 0, obj, 0xA);
            func_800FD050_ovl30(0x1E, D_800FDBB4_ovl30, obj, 4);
            break;
        case 2:
        case 4:
            func_800171E8(obj, 8);
            *(s32*)(obj + 0x50) = 0;
            *(s32*)(obj + 0x54) = 0;
            if (D_800D1C00[0xC] != 0xC) {
                *(s16*)(obj + 0xE) = 0x1B0;
            } else {
                *(s16*)(obj + 0xE) = 0xD0;
            }
            obj[6] = 3;
            func_80050650(0x33, *(s16*)(obj + 0xA) - 0x28,
                          *(s16*)(obj + 0xE) - 0x10, *(s16*)(obj + 0xA) + 0x28,
                          *(s16*)(obj + 0xE), 0x10);
            func_80016490(2, 0xC, obj);
            func_800FD050_ovl30(0x14, D_800FDBB4_ovl30, obj, 3);
            obj[0x94] = 0;
            break;
        }
        func_8002A5C4(0x14, 4, 2);
    }
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) += 1;
}
