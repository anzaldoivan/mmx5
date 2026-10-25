#include "types.h"
#include "addr.h"

extern u8 D_800FB2DC_ovl09[];
extern void func_800F8F80_ovl09(u8*);
extern void func_800F8FE4_ovl09(u8*, s16, s16, u8);
extern s32 func_80016490(s32, s32, void*);

void func_800F8B48_ovl09(u8* a0) {
    s32 v = ((s8*)a0)[0x45];

    if (v == 1) {
        *(u8**)(a0 + 0x68) = D_800FB2DC_ovl09;
        D_1F80004C.bytes[0x86] = v;
        *(s16*)(a0 + 0x7C) = 0x60;
        func_800F8F80_ovl09(a0);
        func_800F8FE4_ovl09(a0, *(s16*)(a0 + 0xA), *(s16*)(a0 + 0xE), 1);
        func_80016490(2, 0x26, 0);
        a0[6]++;
    }
}
