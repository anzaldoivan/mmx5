#include "types.h"
#include "addr.h"

#define func_800EFFE4_ovl04 func_800F87F8_ovl09
#include "shared/func_800EFFE4_ovl04.c"
#undef func_800EFFE4_ovl04

void func_800F880C_ovl09(u8* a0) {
    if (D_1F80004C.bytes[0x85] == 7) {
        D_1F80004C.bytes[0x85] = 0xFF;
    }
    if (D_1F80004C.bytes[0x84] == 7) {
        D_1F80004C.bytes[0x85] = 0;
        D_1F80004C.bytes[0x84] = 0;
        a0[6]++;
    }
}

void func_800F8874_ovl09(ObjFE130* arg0) {
    arg0->unk5 = 2;
    arg0->unk6 = 0;
}
