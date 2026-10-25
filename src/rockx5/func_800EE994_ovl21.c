#include "types.h"
#include "addr.h"

extern u32* D_80098118;
extern u8* func_8002D0E4(void);

#define B(p, o) (*(u8*)((p) + (o)))
#define SB(p, o) (*(s8*)((p) + (o)))
#define H(p, o) (*(u16*)((p) + (o)))
#define SH(p, o) (*(s16*)((p) + (o)))
#define W(p, o) (*(s32*)((p) + (o)))
#define P(p, o) (*(u8**)((p) + (o)))

void func_800EE994_ovl21(u8* a0) {
    u8* a1;
    u8* p;
    u8* prev;
    s32 i;

    a1 = P(a0, 0x50);
    B(a0, 0x16) = 4;
    SB(a0, 0x14) = -1;
    B(a0, 0x3) = 1;
    B(a0, 0x47) = 0;
    H(a0, 0x40) = D_80098118[B(a1, 0x41) - 1] >> 7;
    H(a0, 0x42) = (((B(a1, 0x41) - 1) * 4) % 16) |
                  ((((B(a1, 0x41) - 1) / 4) + 0x1E0) << 6);
    W(a0, 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[B(a1, 0x41) - 1];
    B(a0, 0x15) = 0;
    H(a0, 0x54) = 0;
    B(a0, 0x4) = 1;
    B(a0, 0x5) = 0;
    B(a0, 0x6) = 1;
    switch (SB(a0, 0x2)) {
    case 0:
        H(a0, 0xA) = 0;
        H(a0, 0xE) = 0;
        W(a0, 0x20) = 0x40000;
        W(a0, 0x24) = -0x30000;
        break;
    case 1:
        H(a0, 0xA) = 0x140;
        H(a0, 0xE) = 0;
        W(a0, 0x20) = -0x40000;
        W(a0, 0x24) = -0x30000;
        break;
    case 2:
        H(a0, 0xA) = 0x140;
        H(a0, 0xE) = 0xF0;
        W(a0, 0x20) = -0x40000;
        W(a0, 0x24) = 0x30000;
        break;
    case 3:
        H(a0, 0xA) = 0;
        H(a0, 0xE) = 0xF0;
        W(a0, 0x20) = 0x40000;
        W(a0, 0x24) = 0x30000;
        break;
    case 4:
        SH(a0, 0xA) = -0x80;
        H(a0, 0xE) = 0xB0;
        W(a0, 0x20) = 0x147000;
        W(a0, 0x24) = 0;
        B(a0, 0x47) = 2;
        return;
    }
    for (i = 0; i < 2; i++) {
        p = func_8002D0E4();
        if (p != 0) {
            B(p, 0x0) = 0x51;
            B(p, 0x1) = 0x19;
            B(p, 0x2) = i;
            B(p, 0x16) = 6;
            P(p, 0x50) = a0;
            if (i != 0) {
                P(p, 0x5C) = prev;
            } else {
                P(p, 0x5C) = a0;
            }
            prev = p;
        }
    }
}
