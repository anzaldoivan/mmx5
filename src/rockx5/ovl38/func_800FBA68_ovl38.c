#include "types.h"
#include "addr.h"

extern s32 func_80024548(s32);
extern u8 D_800D1C00[];

void func_800FBA68_ovl38(u8* obj) {
    u8* child;
    u8* t;
    u8* g;
    s32 k;
    s32 n;

    child = *(u8**)(D_1F80004C.bytes + 0x80);
    if (*(signed char*)child == 0) {
        t = D_1F80009C;
        *(u8**)(obj + 0x3C) = t + *(s32*)t;
        g = D_800D1C00;
        g[0x24] = 1;
        g[0x25] = 1;
        *(u8**)(g + 0x20) = obj;
        g[0xA2] = 0x40;
        func_80024548(1);
        n = obj[6];
        obj[0x15] = 0;
        k = 0x1268;
        *(s16*)(obj + 0xA) = k;
        k = 0x7C0;
        obj[3] = 1;
        *(s16*)(obj + 0xE) = k;
        n++;
        obj[6] = n;
    }
}
