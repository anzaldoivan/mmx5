#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);
extern u16 D_8009A120;

void func_80049AD0(u8* obj) {
    s32 m;
    s8 v;

    animate_object(obj);
    move_object(obj);
    func_8002D9EC(obj, 0x20, 0x20);
    if (obj[0x70] != 0 || (((s32(*)())func_8002F8FC)(obj), obj[0x70] != 0) ||
        *(s8*)(obj + 0x98) != 0 || *(s8*)(obj + 3) == 0) {
        obj[4] = 3;
        *(s32*)(obj + 0x68) = 0;
        *(s32*)(obj + 0x50) = 0;
    } else {
        {
            m = D_8009A120 & *(u16*)(obj + 0x8E);
            if (m != 0) {
                if (m & 2) {
                    *(s32*)(obj + 0x20) = 0xFFFE0000;
                    obj[0x15] = 0;
                    *(s32*)(obj + 0x24) = 0;
                    *(u16*)(obj + 0x8E) = 0xC;
                    set_animation_frame(obj, 0, 1);
                    v = 2;
                } else if (m & 1) {
                    obj[0x15] = 0x40;
                    *(s32*)(obj + 0x20) = 0x20000;
                    *(s32*)(obj + 0x24) = 0;
                    *(u16*)(obj + 0x8E) = 0xC;
                    set_animation_frame(obj, 0, 1);
                    v = 1;
                } else if (m & 4) {
                    *(s32*)(obj + 0x20) = 0;
                    *(s32*)(obj + 0x24) = 0x20000;
                    *(u16*)(obj + 0x8E) = 3;
                    set_animation_frame(obj, 1, 1);
                    v = 4;
                } else if (m & 8) {
                    *(s32*)(obj + 0x20) = 0;
                    *(s32*)(obj + 0x24) = 0xFFFE0000;
                    *(u16*)(obj + 0x8E) = 3;
                    set_animation_frame(obj, 2, 1);
                    v = 8;
                } else {
                    goto tick; // !FAKE: goto kept for the matching branch layout
                }
                obj[6] = v;
            }
        tick:
            if (++*(s16*)(obj + 0x8C) >= 5) {
                *(s16*)(obj + 0x8C) = 0;
                player_spawn_weapon(1, *(s8*)(obj + 1), 2, obj);
            }
        }
    }
}
