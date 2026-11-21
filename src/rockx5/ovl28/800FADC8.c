#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FADC8_ovl28(u8* obj) {
    u8* p;
    u8 f;
    u16 e;

    p = *(u8**)(obj + 0x7C);
    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(p + 0x3C);
    obj[0x14] = 0;
    obj[0x16] = 6;
    f = p[0x15];
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    obj[0x15] = f;
    if (f == 0) {
        *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0xD;
    } else {
        *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0xD;
    }
    e = *(u16*)(*(u8**)(obj + 0x7C) + 0xE);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x5C] = 0;
    obj[0x60] = 0;
    *(s32*)(obj + 0x8C) = 0;
    *(s16*)(obj + 0xE) = e - 0x32;
    set_animation(obj, 0x15);
    obj[0x5] = 0;
    obj[0x4]++;
}

void func_800FAEB4_ovl28(u8* obj) {
    if (++*(s32*)(obj + 0x8C) == 0x12) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    animate_object(obj);
    move_object(obj);
}

#define D_800EEBA0_ovl00 func_800FAF10_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
