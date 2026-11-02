#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002B5B4(s32);
extern u8 D_800750C0[];
extern u8 D_800769C0;
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;
extern s32 D_800E92F8;
extern u8 D_800F5688_ovl05;
extern u8 D_800F568C_ovl05;
extern u8 D_800F5690_ovl05;
extern u8 D_800F56B8_ovl05;
extern u8 D_800F56D0_ovl05;
extern u8 D_800F57DC_ovl05;
extern u8 D_800F5964_ovl05[];

void func_800F2378_ovl05(u8* p) {
    s32 idx;
    s8 mode;
    u8* b;

    p[0] = 0x41;
    idx = func_8002B5B4(0x25) & 0xFF;
    *(u16*)(p + 0x40) = D_80098118[idx] >> 7;
    *(s32*)(p + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[idx];
    *(u16*)(p + 0x42) =
        ((idx * 4 + 0x18) % 16) | (((idx + 6) / 4 + 0x1E0) << 6);
    p[0x14] = D_8009A0B4;
    mode = ((s8*)p)[2];
    p[0x16] = 0x30;
    if (mode == 0) {
        p[0x75] = 1;
        p[0x15] = 0;
        *(u8**)(p + 0x68) = &D_800F5688_ovl05;
        *(u8**)(p + 0x54) = &D_800F568C_ovl05;
        *(u8**)(p + 0x58) = D_800750C0;
        p[0x5C] = 0x20;
        p[0x47] = 0;
        *(u8**)(p + 0x30) = &D_800F56B8_ovl05;
        *(u16*)(p + 0x42) = 0x78CC;
        p[5] = 0;
    } else if (mode == 1) {
        D_800F5964_ovl05[0] = 0;
        *(u8**)(p + 0x54) = &D_800F5690_ovl05;
        *(u8**)(p + 0x58) = &D_800769C0;
        *(u8**)(p + 0x30) = &D_800F56D0_ovl05;
        b = D_8009A1F8;
        *(u16*)(p + 0x7C) = *(u16*)(b + 0x26);
        *(u16*)(p + 0x7E) = *(u16*)(b + 0x24);
        p[5] = mode;
    } else {
        *(u8**)(p + 0x30) = &D_800F57DC_ovl05;
        p[0x16] = 0;
        p[0] |= 0x10;
        if (mode == 2) {
            func_800171E8(p, 0);
        } else if (mode == 3) {
            func_800171E8(p, 1);
        } else if (mode == 4) {
            func_800171E8(p, 2);
        } else if (mode == 5) {
            func_800171E8(p, 3);
        } else if (mode == 6) {
            func_800171E8(p, 4);
        }
        p[5] = 2;
    }
    p[4]++;
    if (D_800D1C1D == 2) {
        D_800E92F8 = 1;
    }
}
