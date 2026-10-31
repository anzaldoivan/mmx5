/* Shared body (DK-5), from the banked draft of func_800F075C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800F0F28_ovl11(u8* a0);
extern u8 D_8009A197;
extern u8 D_800F988C_ovl11[];
extern void* D_800F98A8_ovl11[];

void DEDUP_NAME(u8* a0) {
    s32 r;
    u8 f;

    if (D_8009A197 == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        ((void (*)(u8*))D_800F98A8_ovl11[(s8)a0[5]])(a0);
        func_800F0F28_ovl11(a0);
    }
    r = func_80031DD0(a0);
    func_800317B8(a0);
    if (r < 0 || ((f = a0[0x70]) & 0xC) == 0xC || (f & 3) == 3) {
        func_8004D4F4(5, D_800F988C_ovl11, a0);
        a0[3] = 0;
        *(s16*)(a0 + 0x7C) = 0x1E;
        *(s16*)(a0 + 0x7E) = 5;
        a0[4]++;
        return;
    }
    if (func_8002D938(a0, 0x60, 0x40) == 0) {
        func_8002D9EC(a0, 0x30, 0x30);
        return;
    }
    a0[4] = 4;
}
