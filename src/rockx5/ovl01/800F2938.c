#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "addr.h"

extern s32 func_800F2F44_ovl01(u8* arg0);

void func_800F2938_ovl01(u8* obj) {
    set_animation(obj, 0);
    if (func_800F2F44_ovl01(obj) == 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
}

extern s32 D_8009A0A8;

void func_800F298C_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 3) != 0) {
        obj[0x15] = (*(s32*)(obj + 8) <= D_8009A0A8) << 6;
        D_1F80004C.bytes[0x80] = 30;
        obj[6]++;
        *(s32*)(D_1F80004C.bytes + 0x88) = *(s32*)(obj + 0xC);
    }
}
