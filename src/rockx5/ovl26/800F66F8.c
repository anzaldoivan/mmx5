#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_8009A0B4;
extern s32 D_800FA2AC_ovl26[];
extern s32 D_800FA2CC_ovl26[];

void func_800F66F8_ovl26(u8* obj) {
    obj[0x14] = D_8009A0B4;
    if (((s8*)obj)[2] == 0) {
        play_sound(2, 0x64, obj);
        obj[0x16] = 4;
        set_animation(obj, 0x18);
    } else {
        obj[0x16] = 4;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x5000;
        *(s32*)(obj + 0x20) = D_800FA2AC_ovl26[random_byte() & 7];
        *(s32*)(obj + 0x24) = D_800FA2CC_ovl26[random_byte() & 7];
        set_animation(obj, 0);
    }
    obj[4] = 1;
    obj[6] = 0;
}

void func_800F67C8_ovl26(u8* p) {
    s32 a;
    s32 b;

    animate_object(p);
    func_8002D89C(p);
    b = ((s8*)p)[2];
    if (b == 0) {
        b = ((s8*)p)[0x45];
        a = 1;
    } else {
        *(u16*)(p + 0x42) = *(u16*)(*(u8**)(p + 0x50) + 0x42);
        apply_object_motion(p);
        a = is_off_screen(p, 0x20, 0x20);
        b = 1;
    }
    if (a == b) {
        p[4] = 2;
    }
}

#define D_800EEBA0_ovl00 func_800F6844_ovl26
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
