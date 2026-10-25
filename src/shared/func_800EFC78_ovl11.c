/* Shared body (DK-5), from the banked draft of func_800EFC78_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern u32* D_80098118;
extern u8 D_800F9734_ovl11[];
extern u8 D_800F96C8_ovl11[];
extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8*, s32);
extern u8* func_8002D27C(void);

#define B(p, o) (*(u8*)((p) + (o)))
#define SB(p, o) (*(s8*)((p) + (o)))
#define H(p, o) (*(u16*)((p) + (o)))
#define W(p, o) (*(s32*)((p) + (o)))
#define SCR20 D_1F800020.s32s
void DEDUP_NAME(u8* a0) {
    u8* p;
    s32 s0;
    s32 v;
    u8 t;

    t = D_8009A0A0[0x14];
    B(a0, 0x0) = 0x41;
    B(a0, 0x4) = 1;
    B(a0, 0x5) = 0;
    B(a0, 0x16) = 6;
    B(a0, 0x7) = 0;
    W(a0, 0x20) = 0;
    W(a0, 0x24) = 0;
    W(a0, 0x28) = 0;
    W(a0, 0x2C) = 0;
    B(a0, 0x14) = t;
    if (SB(a0, 0x2) == 2) {
        W(a0, 0x20) = 0x50000;
        W(a0, 0x28) = -0x1000;
        B(a0, 0x87) = 0x50;
        B(a0, 0x16) = 0x22;
    }
    W(a0, 0x30) = (s32)D_800F9734_ovl11;
    H(a0, 0x40) = D_80098118[func_8002B5B4(0x85)] >> 7;
    W(a0, 0x3C) = (s32)SCR20 + SCR20[func_8002B5B4(0x85)];
    s0 = func_8002B5B4(0x85);
    v = func_8002B5B4(0x85);
    H(a0, 0x42) = ((s0 * 4 + 0x18) % 16) | (((v + 6) / 4 + 0x1E0) << 6);
    W(a0, 0x68) = (s32)D_800F96C8_ovl11;
    if (SB(a0, 0x2) == 0) {
        W(a0, 0x24) = 0;
        W(a0, 0x2C) = 0x8000;
        func_800171E8(a0, 4);
    } else {
        func_800171E8(a0, 0);
    }
    p = func_8002D27C();
    if (p != 0) {
        B(p, 0x0) = 0x41;
        B(p, 0x1) = 0x22;
        B(p, 0x15) = 0;
        B(p, 0x2) = 0;
        W(p, 0x3C) = W(a0, 0x3C);
        H(p, 0x40) = H(a0, 0x40);
        W(p, 0x30) = W(a0, 0x30);
        W(p, 0x8) = W(a0, 0x8);
        H(p, 0xE) = H(a0, 0xE) - 0x20;
        H(p, 0x42) = H(a0, 0x42);
        B(p, 0x14) = D_8009A0A0[0x14];
        W(p, 0x50) = (s32)a0;
    }
}
