#include "types.h"

extern int func_8002DAA0();
extern u8 D_8009A0A0[];
extern void* D_800FDE90_ovl06[];

void func_800F2A4C_ovl06(u8* arg0) {
    u8* p;
    u8* q;
    u8 a;
    u8 t;

    p = D_8009A0A0;
    if (*(s8*)(p + 0xD0) == 0) {
        *(u16*)(arg0 + 0x88) = *(u16*)(p + 0x7C);
        *(u16*)(arg0 + 0x8A) = *(u16*)(p + 0x80);
    } else {
        *(u16*)(arg0 + 0x88) = 0;
        *(u16*)(arg0 + 0x8A) = 0;
    }
    q = D_8009A0A0;
    if (*(s8*)(q + 0xCC) != 0) {
        func_8002DAA0(arg0);
        return;
    }
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    a = arg0[0x70];
    t = arg0[0x71];
    arg0[0x71] = 0;
    arg0[0xA8] = a | t;
    ((void (*)(u8*))D_800FDE90_ovl06[*(s8*)(arg0 + 4)])(arg0);
    arg0[0x5C] &= 0x7F;
}
