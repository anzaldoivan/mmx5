#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_8002E024(void*, void*);
extern void set_velocity_from_angle(void*, s32);

void func_800F26BC_ovl29(u8* arg0) {
    s32 v;

    if (*(s16*)(arg0 + 0x7C) == 0) {
        set_velocity_from_angle(arg0, func_8002E024(arg0, g_Player));
        if (arg0[0x15] == 0) {
            v = *(s32*)(arg0 + 0x20);
            if (v < 0) {
                goto set; // !FAKE: goto kept for the matching branch layout
            }
            *(s16*)(arg0 + 0x7C) = 0x3C;
        } else {
            v = *(s32*)(arg0 + 0x20);
            if (v > 0) {
            set:
                *(s32*)(arg0 + 0x88) = v;
                *(s32*)(arg0 + 0x8C) = *(s32*)(arg0 + 0x24);
                set_animation(arg0, 2);
                arg0[5] = 4;
                arg0[6] = 2;
            } else {
                *(s16*)(arg0 + 0x7C) = 0x3C;
            }
        }
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
    } else {
        *(s16*)(arg0 + 0x7C) = *(s16*)(arg0 + 0x7C) - 1;
    }
}
