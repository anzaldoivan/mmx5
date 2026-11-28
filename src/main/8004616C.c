#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern u8 D_80076E54[];
extern u8 D_80076E58[];
extern u8 D_8007B490[];

void func_8004616C(u8* obj) {
    u8* p;
    u8* q;
    s32 t;

    obj[0] = 1;
    obj[3] = 1;
    obj[0x64] = 1;
    *(u8**)(obj + 0x50) = D_80076E54;
    *(u8**)(obj + 0x68) = D_80076E58;
    p = D_1F800014;
    *(u8**)(obj + 0x38) = p + *(s32*)(p + 0x2C);
    q = D_1F80001C.bytes;
    t = *(s32*)(q + 0x18);
    *(u8**)(obj + 0x30) = D_8007B490;
    *(s16*)(obj + 0x40) = 0x540;
    *(s16*)(obj + 0x42) = 0x7802;
    obj[0x16] = 1;
    *(u8**)(obj + 0x3C) = q + t;
    if (obj[0x15] != 0) {
        *(s32*)(obj + 0x20) = 0xA0000;
    } else {
        *(s32*)(obj + 0x20) = -0xA0000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    set_animation(obj, 0);
    obj[5] = 0;
    obj[4]++;
    player_spawn_visual(1, 0x1B, 7, 0);
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_80046258(u8* self) {
    if (is_off_screen(self, 0x20, 0x20) == 0) {
        animate_object(self);
        move_object(self);
        if ((D_8009A420_as_s32 & 3) == 0) {
            self[0x64]++;
        }
        return;
    }
    self[3] = 0;
    self[4] = 2;
    *(s32*)(self + 0x50) = 0;
}
#undef D_8009A420_as_s32

#include "shared/func_800462D4.c"
