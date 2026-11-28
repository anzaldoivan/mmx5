#include "types.h"
#include "mmx5/globals.h"

extern void player_clear_dash(u8*);
extern void player_set_animation_frame(u8* obj, s32 arg1, s32 arg2);
extern void set_stand_animation_by_hp(u8* obj);
extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void func_8003AA4C(u8* obj) {
    s32 a2;
    u8 t;

    if (obj[0x89] & 8) {
        obj[0x67] = 0;
        obj[0x86] = 0;
        player_clear_dash(obj);
        if (player_check_script(obj) == 0) {
            obj[5] = 2;
            obj[6] = 0;
            if (*(s8*)(obj + 2) == 0 && *(s8*)(obj + 0x8E) != 0) {
                a2 = obj[0x91] < 9;
                if (obj[0x91] < 5) {
                    a2 = 2;
                }
                player_set_animation_frame(obj, 0x5E, a2);
                t = obj[0x91];
                if (t >= 9) {
                    obj[0x44] = t - 8;
                }
            } else {
                set_stand_animation_by_hp(obj);
            }
        }
    } else {
        player_set_animation_shooting(obj, 0xB);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s8*)(obj + 0x67) = -1;
        *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
        if (*(s8*)(obj + 0x84) != 0) {
            obj[0x84] = 0;
            *(s8*)(obj + 0x8C) = -1;
        }
        obj[5] = 7;
        obj[6] = 0;
    }
}
