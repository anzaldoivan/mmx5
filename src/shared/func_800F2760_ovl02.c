#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2760_ovl02(u8* arg0) {
    D_1F80004C.bytes[0x82] = 0;
    set_animation(arg0, 0);
    *(s16*)(arg0 + 0x7C) = 0x5A;
    arg0[6]++;
}

#define SPAD D_1F80004C.bytes

void func_800F27A8_ovl02(u8* obj) {
    u8 v;

    if (--*(s16*)(obj + 0x7C) == -1) {
        v = 4;
        if (SPAD[0x80] == 0) {
            v = 3;
        }
        obj[5] = v;
        SPAD[0x80] ^= 1;
        obj[6] = 0;
    }
}
