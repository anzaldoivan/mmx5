#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern s32 try_enter_ladder(u8* arg0);
extern s32 func_8003EF28(u8* arg0);
extern s32 func_800437FC(u8* arg0);
extern s32 player_check_dash_jump_walk(u8* arg0);
extern s32 func_8004387C(u8* arg0);
extern s32 func_80041A54(u8* arg0);
extern void func_8003A670(u8* arg0);

void update_dash_stop(u8* obj) {
    s32 mask;

    if (try_enter_ladder(obj) != 0) {
        return;
    }
    if (func_8003EF28(obj) != 0) {
        return;
    }
    if (func_800437FC(obj) != 0) {
        return;
    }
    if (player_check_dash_jump_walk(obj) != 0) {
        return;
    }
    if (func_8004387C(obj) != 0) {
        return;
    }
    if (func_80041A54(obj) != 0) {
        return;
    }
    if (*(s8*)(obj + 0x45) & 0x80) {
        obj[0x45] &= 0x7F;
        play_sound(1, 6, obj);
    }
    if ((obj[0x45] & 0x40) && *(s8*)(obj + 0x85) == 0) {
        mask = 2;
        if (obj[0x15] != 0) {
            mask = 1;
        }
        if (obj[0x89] & mask) {
            *(s32*)(obj + 0x20) = 0;
        }
        if (*(s32*)(obj + 0x20) != 0) {
            apply_object_motion(obj);
            if (obj[0x15] != 0) {
                if (*(s32*)(obj + 0x20) < 0) {
                    *(s32*)(obj + 0x20) = 0;
                }
            } else {
                if (*(s32*)(obj + 0x20) > 0) {
                    *(s32*)(obj + 0x20) = 0;
                }
            }
        }
    }
    if (*(s8*)(obj + 0x46) < 0) {
        func_8003A670(obj);
    } else {
        player_update_animation_shooting(obj, 0x11);
    }
}
