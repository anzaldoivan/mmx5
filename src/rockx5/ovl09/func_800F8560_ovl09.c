#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern s8 D_800D1C26;
extern u8 D_8009A1F8[];

void func_800F8560_ovl09(u8* arg0) {
    u8* q;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        ((s32(*)())func_8003D2C4)();
        q = D_8009A1F8;
        D_800D1C26 = 0;
        *(u16*)(q + 0x26) = *(u16*)(D_1F80004C.bytes + 0x80);
        *(u16*)(q + 0x24) = *(u16*)(D_1F80004C.bytes + 0x82);
        func_8002D720(arg0);
    }
}
