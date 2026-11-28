#include "types.h"
#include "mmx5/ovl10.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

void func_800F57C0_ovl10(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0x78;
    set_animation(obj, 0);
    obj[6] = 1;
}

extern void func_800F6250_ovl10(void*);

void func_800F5808_ovl10(u8* obj) {
    func_800F6250_ovl10(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6] = 2;
    }
}

void func_800F5854_ovl10(u8* obj) {
    animate_object(obj);
    obj[0x88] = 0;
    switch (obj[0x8A]) {
    case 0:
        if ((((u32(*)())random_byte)() & 0xF) < 6) {
            obj[0x89] = 0;
        } else {
            obj[0x89] = 1;
        }
        break;
    case 1:
        if ((((u32(*)())random_byte)() & 0xF) < 12) {
            obj[0x89] = 0;
        } else {
            obj[0x89] = 1;
        }
        break;
    case 2:
        if ((((u32(*)())random_byte)() & 0xF) < 10) {
            obj[0x89] = 0;
        } else {
            obj[0x89] = 1;
        }
        break;
    }
    obj[5] = D_800FBE00_ovl10.u[obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
    obj[6] = 0;
}
