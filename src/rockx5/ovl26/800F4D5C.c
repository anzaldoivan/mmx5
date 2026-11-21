#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/graphics.h"

void func_800F4D5C_ovl26(u8* obj) {
    animate_object(obj);
    D_1F80004C.bytes[0x94] = (u32)random_byte() % 3;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 0x1E;
    obj[7] = 0;
    obj[6]++;
}

void func_800F4DD0_ovl26(u8* a0) {
    u8* s;

    animate_object(a0);
    s = D_1F80004C.bytes;
    if (s[0x97] == 1) {
        s[0x97] = 0;
        set_animation(a0, 6);
        a0[6]++;
    }
}

void func_800F4E2C_ovl26(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 7) == 0x20) {
        obj[7] = 0;
        obj[6]++;
    }
}

#include "shared/func_800F4E70_ovl26.c"
