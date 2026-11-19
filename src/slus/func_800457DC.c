#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_80044F78(void* arg0);

void func_800457DC(u8* arg0) {
    s32 d;
    s32 lim;
    u8* g;

    if (is_off_screen(arg0, *(s16*)(arg0 + 0x8E), *(s16*)(arg0 + 0x90)) == 0) {
        animate_object(arg0);
        if (*(s8*)(arg0 + 0x98) == 0) {
            move_object(arg0);
            if (arg0[0x70] != 0 ||
                (((s32(*)())func_8002F8FC)(arg0), arg0[0x70] != 0)) {
                func_80044F78(arg0);
            } else {
                lim = *(s16*)(arg0 + 0x92);
                d = *(s16*)(arg0 + 0x8C) - *(s16*)(arg0 + 0xA);
                if ((d >= 0)
                        ? (lim < d)
                        : (lim < *(s16*)(arg0 + 0xA) - *(s16*)(arg0 + 0x8C))) {
                    g = g_Player;
                    arg0[3] = 0;
                    arg0[4] = 3;
                    *(s32*)(arg0 + 0x50) = 0;
                    *(s32*)(arg0 + 0x68) = 0;
                    g[0x98]--;
                    arg0[4] = 2;
                    if (*(s8*)(arg0 + 1) == 0x2D) {
                        set_animation(arg0, 1);
                    } else {
                        set_animation(arg0, 2);
                    }
                }
                func_8002D9EC(arg0, *(s16*)(arg0 + 0x8E), *(s16*)(arg0 + 0x90));
                return;
            }
        }
    }
    arg0[3] = 0;
    arg0[4] = 3;
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x68) = 0;
}
