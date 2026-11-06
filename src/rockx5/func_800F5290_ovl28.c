#include "types.h"
#include "addr.h"

extern void func_8003D29C(s32, s32);
extern void func_80024548(s32);
extern s32 func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800F5290_ovl28(u8* arg0) {
    s32 v;
    s16 t;

    v = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = v;
    t = v;
    if (t == 0) {
        func_8003D29C(0x14, 0x40);
    } else if (t == 0x30) {
        u8* b = D_8009A1F8;
        *(s16*)(b + 0x26) = 0x1910;
        *(s16*)(b + 0x24) = 0x1910;
    }
    if (**(s8**)(D_1F80004C.bytes + 0x80) == 0) {
        u8* o = D_800D1C00;
        o[0x24] = 1;
        o[0x25] = 0;
        *(u8**)(o + 0x20) = arg0;
        o[0xA2] = 0x30;
        func_80024548(1);
        arg0[3] = 1;
        func_80016490(1, 0xD, arg0);
        arg0[6]++;
    }
}
