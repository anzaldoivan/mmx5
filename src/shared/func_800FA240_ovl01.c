#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern signed char D_800D1C0C;
extern u8 D_800FD5A8_ovl01[];
extern u8 D_800FD5AC_ovl01[];

void func_800FA240_ovl01(u8* obj) {
    obj[0x94] = 0;
    set_animation(obj, 0xE);
    *(u8**)(obj + 0x50) = D_800FD5A8_ovl01;
    *(u8**)(obj + 0x54) = D_800FD5AC_ovl01;
    obj[6] = 1;
    *(s16*)(obj + 0x7C) = 0;
    *(s32*)(obj + 0x68) = 0;
    if (D_800D1C0C != 12) {
        *(s16*)(obj + 0xA) = 0x25E0;
        *(s16*)(obj + 0xE) = 0xB0;
    } else {
        *(s16*)(obj + 0xA) = 0x2E0;
        *(s16*)(obj + 0xE) = -0x30;
    }
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x4000;
}

extern void func_800FB348_ovl01(u8* obj);

void func_800FA2CC_ovl01(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x45] == 1) {
        obj[5] = 3;
        obj[6] = 0;
        func_800FB348_ovl01(obj);
    }
}
