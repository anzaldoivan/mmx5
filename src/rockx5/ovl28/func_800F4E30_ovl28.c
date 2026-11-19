#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern s32 D_8009A0A8;

void func_800F4E30_ovl28(u8* obj) {
    func_8002C338(0x13C, D_1F800030 + 0x60, 1);
    func_8002C338(0x13D, D_1F800030 + 0x80, 1);
    *(u16*)(obj + 0x42) = 0x7CCC;
    play_sound(2, 0x6C, obj);
    func_8003D29C(0x14, (D_8009A0A8 <= *(s32*)(obj + 8)) << 6);
    obj[5] = 1;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 0xB);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x61] = 0x19;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    if (*(s32*)(obj + 0x24) > 0) {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s32*)(obj + 0x2C) = 0x4200;
    func_8002D9EC(obj, 0x60, 0x60);
}
