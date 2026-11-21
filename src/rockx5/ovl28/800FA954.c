#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FA954_ovl28(u8* obj) {
    u8* parent = *(u8**)(obj + 0x7C);

    *(u16*)(obj + 0x40) = *(u16*)(parent + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(parent + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(parent + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(parent + 0x3C);
    obj[0x14] = 0;
    obj[0x16] = 1;
    obj[0x15] = parent[0x15];
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    set_animation(obj, 0x11);
    obj[0x5C] = 0;
    obj[0x60] = 0;
    play_sound(2, 0x8D, obj);
    obj[0x4]++;
    obj[0x5] = 0;
}

void func_800FAA18_ovl28(ObjFA798* obj) {
    if (obj->f46 == 0) {
        obj->f4 = 2;
    }
    if (obj->parent->state == 2) {
        obj->f4 = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    animate_object(obj);
    move_object(obj);
}

#define D_800EEBA0_ovl00 func_800FAA88_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800FAAA8_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
