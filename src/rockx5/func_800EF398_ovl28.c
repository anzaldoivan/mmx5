#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern s32 func_800171E8(u8* obj, s32 state);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();
extern u32* D_80098118;
extern u8 D_800FD7AC_ovl28[];

void func_800EF398_ovl28(u8* a0) {
    s32 r0;
    s32 r1;

    if (((s8*)a0)[4] == 0) {
        *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x97)] >> 7;
        *(s32*)(a0 + 0x3C) =
            (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x97)];
        r0 = func_8002B5B4(0x97);
        r1 = func_8002B5B4(0x97);
        *(u16*)(a0 + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        *(u8**)(a0 + 0x30) = D_800FD7AC_ovl28;
        a0[0x14] = 0;
        a0[0x15] = 0;
        func_800171E8(a0, 0);
        a0[0x16] = 0x20;
        ((s8*)a0)[4]++;
        return;
    }
    if (func_8002D938(a0, 0x40, 0x30) == 0) {
        func_8002D9EC(a0, 0x40, 0x30);
        return;
    }
    func_8002D7A0(a0);
}
