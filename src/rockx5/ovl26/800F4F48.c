#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/graphics.h"

void func_800F4F48_ovl26(u8* obj) {
    animate_object(obj);
    D_1F80004C.bytes[0x94] = (u32)random_byte() % 3 + 3;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 30;
    obj[7] = 0;
    obj[6]++;
}

#define G D_1F80004C.bytes

void func_800F4FC0_ovl26(u8* obj) {
    animate_object(obj);
    if (G[0x97] == 1) {
        set_animation(obj, 6);
        obj[6]++;
    }
}
#undef G

#define G D_1F80004C.bytes

void func_800F5018_ovl26(u8* obj) {
    animate_object(obj);
    if (G[0x97] == 0) {
        obj[6]++;
    }
}
#undef G

void func_800F5068_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 7) == 0x20) {
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6]++;
    }
}

#include "shared/func_800F50AC_ovl26.c"

void func_800F50FC_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 7) == 0x10) {
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6]++;
    }
}

#define func_800F50AC_ovl26 func_800F5140_ovl26
#include "shared/func_800F50AC_ovl26.c"
#undef func_800F50AC_ovl26

void func_800F5190_ovl26(u8* obj) {
    animate_object(obj);
    if ((signed char)obj[7] == 0x10) {
        obj[7] = 0;
        obj[6]++;
    }
}

#define func_800F4E70_ovl26 func_800F51D4_ovl26
#include "shared/func_800F4E70_ovl26.c"
#undef func_800F4E70_ovl26
