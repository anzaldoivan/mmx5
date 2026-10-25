#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800FCAE0_ovl38(u8* a0, u8 a1);

void func_800FC9F0_ovl38(u8* a0) {
    if (((s8*)a0)[0x45] != 0) {
        func_80016490(2, 0x9E, a0);
        D_1F80004C.bytes[0x91] = 7;
        func_800FCAE0_ovl38(a0, 1);
        func_800FCAE0_ovl38(a0, 2);
        func_800FCAE0_ovl38(a0, 3);
        *(s16*)(a0 + 0x7C) = 0x5A;
        a0[6]++;
    }
}
