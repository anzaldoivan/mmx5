#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern s32 func_800171E8(u8* obj, s32 state);
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();
extern u32* D_80098118;
extern s32 D_8009A420;
extern u8 D_800F490C_ovl02;

void func_800F3440_ovl02(u8* p) {
    s32 r0;
    s32 r1;

    if (((s8*)p)[4] == 0) {
        *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x94)] >> 7;
        *(s32*)(p + 0x3C) =
            (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x94)];
        r0 = func_8002B5B4(0x94);
        r1 = func_8002B5B4(0x94);
        *(u16*)(p + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        *(u8**)(p + 0x30) = &D_800F490C_ovl02;
        p[0x14] = 0;
        p[0x15] = 0;
        func_800171E8(p, 0);
        p[0x16] = 0;
        p[4]++;
    } else {
        func_80017214(p, ((s8*)p)[2], (D_8009A420 % 102) / 17);
        if (func_8002D938(p, 0x20, 0x20) == 0) {
            func_8002D9EC(p, 0x20, 0x20);
        } else {
            func_8002D7A0(p);
        }
    }
}
