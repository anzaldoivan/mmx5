#include "types.h"
#include "mmx5/system.h"
#include "addr.h"

void func_800FC8A8_ovl39(u8* a0) {
    u8* p = D_1F80004C.bytes;
    u32 r;

    p[0x88] ^= 1;
    r = random_byte();
    *(s16*)(a0 + 0x7E) = 0x18;
    a0[6]++;
    *(s16*)(a0 + 0x7C) = (u8)(r % 7) * 10 + 60;
}

extern void func_800FCE1C_ovl39(void* arg0, u8 arg1);
extern u8 D_800FEB34_ovl39[];

void func_800FC93C_ovl39(u8* arg0) {
    s32 t;
    s32 n;
    u8 v;
    u8* p;

    if (*(s16*)(arg0 + 0x7C) != 0) {
        *(s16*)(arg0 + 0x7C) = *(u16*)(arg0 + 0x7C) - 1;
        return;
    }
    t = *(u16*)(arg0 + 0x7E) - 1;
    *(u16*)(arg0 + 0x7E) = t;
    if ((t << 16) != 0) {
        *(s32*)(arg0 + 0x54) = 0;
        func_800FCE1C_ovl39(arg0, arg0[0x7E] & 1);
        return;
    }
    func_800FCE1C_ovl39(arg0, D_1F80004C.bytes[0x88] ^ 1);
    p = D_1F80004C.bytes;
    n = p[0x87] + 1;
    p[0x87] = n;
    v = D_800FEB34_ovl39[(n & 0xFF) + D_1F80004C.bytes[0x86] * 2];
    arg0[6] = 0;
    arg0[5] = v;
}

#define D_800EEC60_ovl00 func_800FCA0C_ovl39
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
