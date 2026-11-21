#include "types.h"
#include "mmx5/object.h"

extern s16 D_8009A0AE;

s32 func_800F3668_ovl00(u8* obj) {
    s32 v;
    s8 n;

    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    if (D_8009A0AE >= *(s16*)(obj + 0xE)) {
        v = 0xFFFF0000;
        n = 1;
    } else {
        v = 0x10000;
        n = 2;
    }
    *(s32*)(obj + 0x24) = v;
    obj[6] = n;
    return v;
}

extern s16 D_8009A0AE;

void func_800F36B4_ovl00(u8* obj) {
    move_object(obj);
    if (D_8009A0AE <= *(s16*)(obj + 0xE)) {
        obj[5] = 1;
        obj[6] = 0;
    }
}

extern s16 D_8009A0AE;

void func_800F36FC_ovl00(u8* obj) {
    move_object(obj);
    if (D_8009A0AE >= *(s16*)(obj + 0xE)) {
        obj[5] = 1;
        obj[6] = 0;
    }
}
