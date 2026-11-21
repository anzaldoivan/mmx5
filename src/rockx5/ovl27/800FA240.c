#include "types.h"
#include "mmx5/system.h"
#include "addr.h"

void func_800FA240_ovl27(u8* arg0) {
    *(s16*)(arg0 + 0x7C) = 0x28;
    arg0[6]++;
}

void func_800FA258_ovl27(u8* arg0) {
    s16 t;

    t = --*(s16*)(arg0 + 0x7C);
    if (t == -1) {
        D_1F80004C.bytes[0x88] = 1;
        D_1F80004C.bytes[0x8B] = (u32)random_byte() % 3 + 1;
        arg0[6]++;
    }
}

void func_800FA2F0_ovl27(ObjFE130* arg0) {
    arg0->unk5 = 4;
    arg0->unk6 = 0;
}
