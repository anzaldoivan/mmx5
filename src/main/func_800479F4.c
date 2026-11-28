#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8* find_free_visual_obj(void);

void func_800479F4(u8* obj) {
    s32 m;
    u8* p;
    u16 x;

    m = 2;
    if (obj[0x15] != 0) {
        m = 1;
    }
    if (obj[0x71] & m) {
        play_sound(0, 6, obj);
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x21;
            p[1] = 3;
            p[2] = 0;
            p[0x14] = obj[0x14];
            *(u8**)(p + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[1];
            *(u32***)(p + 0x30) = g_visual_animation_tables.p;
            *(s16*)(p + 0x40) = 0;
            *(s16*)(p + 0x42) = 0x7802;
            p[0x16] = 1;
            x = *(u16*)(obj + 0xA);
            *(s16*)(p + 0xA) = x;
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE);
            p[0x15] = obj[0x15] ^ 0x40;
            if (obj[0x15] != 0) {
                *(s16*)(p + 0xA) = x + 4;
            } else {
                *(s16*)(p + 0xA) = x - 4;
            }
        }
    }
    set_animation(obj, 3);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x68) = 0;
    obj[4] = 2;
    obj[5] = 0;
}
