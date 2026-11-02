#include "types.h"

extern u8* func_8002D1A4();
extern u8 D_800FA424_ovl26[];

void func_800F72C0_ovl26(u8* arg0, u8 arg1) {
    u8* a;
    u8* b;

    a = func_8002D1A4();
    if (a != 0) {
        a[0] = 0x41;
        a[1] = 0x20;
        a[2] = arg1;
        *(u8**)(a + 0x7C) = arg0;
        a[0x15] = arg0[0x15];
        *(u16*)(a + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(a + 0xE) = *(u16*)(arg0 + 0xE);
        *(u16*)(a + 0x42) = *(u16*)(arg0 + 0x42);
        *(u8**)(a + 0x30) = D_800FA424_ovl26;
        *(s32*)(a + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(a + 0x40) = *(u16*)(arg0 + 0x40);
        a[0x14] = arg0[0x14];
    }
    if (arg0[2] < 2) {
        b = func_8002D1A4();
        if (b != 0) {
            b[0] = 0x41;
            b[1] = 0x20;
            b[2] = arg1 + 1;
            *(u8**)(b + 0x7C) = arg0;
            b[0x15] = arg0[0x15];
            *(u16*)(b + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(b + 0xE) = *(u16*)(arg0 + 0xE);
            *(u16*)(b + 0x42) = *(u16*)(arg0 + 0x42);
            *(u8**)(b + 0x30) = D_800FA424_ovl26;
            *(s32*)(b + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(b + 0x40) = *(u16*)(arg0 + 0x40);
            b[0x14] = arg0[0x14];
            *(u8**)(b + 0x8C) = a;
        }
    }
}
