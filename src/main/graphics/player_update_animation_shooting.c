#include "types.h"
#include "mmx5/globals.h"

extern void player_set_animation_frame(u8* obj, s32 arg1, s32 arg2);

void player_update_animation_shooting(u8* obj, s32 arg1) {
    s32 n;
    s8 saved;

    if (*(s8*)(obj + 2) == 0) {
        n = arg1 + 0x70;
        if (*(s8*)(obj + 0x90) != 0) {
            saved = *(s8*)(obj + 0x44);
            player_set_animation_frame(obj, arg1, obj[0x45] & 0x3F);
            *(s8*)(obj + 0x44) = saved;
        } else if (*(s8*)(obj + 0x8E) != 0 && obj[0x17] != n) {
            saved = *(s8*)(obj + 0x44);
            player_set_animation_frame(obj, n, obj[0x45] & 0x3F);
            *(s8*)(obj + 0x44) = saved;
        }
    }
}
