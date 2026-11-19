/* Shared body (DK-5), from the banked draft of func_800F01A0_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void silence_sound(s32, s32);

#define ABS(x) ((x) < 0 ? -(x) : (x))

void DEDUP_NAME(Obj01A0* arg0) {

    arg0->timer8C--;
    if (arg0->timer8C == 0) {
        if (arg0->facing == 0 ? D_8009A0AA < arg0->x : D_8009A0AA > arg0->x) {
            set_animation(arg0, 3);
            arg0->vx = 0;
            silence_sound(2, 0x51);
            arg0->state = 5;
            goto set; // !FAKE: state changes share the target's single set tail
        }
    }
    if (--arg0->timer82 == 0) {
        arg0->timer82 = 30;
        if ((random_byte() & 7) < 5U) {
            arg0->timer7C = 10;
            arg0->vx = 0;
            arg0->state = 7;
            goto set; // !FAKE: state changes share the target's single set tail
        }
    }
    if (arg0->timer89 != 0) {
        arg0->timer89--;
    }
    animate_object(arg0);
    if (arg0->fast == 0) {
        if (ABS(((Player01A0*)g_Player)->y - arg0->y) < 0x31) {
            if (arg0->facing == 0) {
                if (arg0->posX - ((Player01A0*)g_Player)->posX > 0x3FFFF) {
                    arg0->fast = 1;
                    set_animation(arg0, 7);
                }
            } else if (((Player01A0*)g_Player)->posX - arg0->posX > 0x3FFFF) {
                arg0->fast = 1;
                set_animation(arg0, 7);
            }
        }
    } else {
        if (ABS(((Player01A0*)g_Player)->posX - arg0->posX) <= 0x3FFFF) {
            arg0->fast = 0;
            set_animation(arg0, 1);
        }
    }
    if (arg0->facing == 0 ? arg0->hitFlags & 2 : arg0->hitFlags & 1) {
        arg0->timer7C = 20;
        arg0->ay = 0;
        arg0->vy = 0;
        arg0->state = 4;
        goto set; // !FAKE: state changes share the target's single set tail
    }
    if (arg0->timer89 == 0) {
        if (arg0->facing == 0 ? ((PlayerA01A0*)g_Player)->x > arg0->x
                              : ((PlayerA01A0*)g_Player)->x < arg0->x) {
            arg0->timer7C = 20;
            arg0->ay = -0x2000;
            arg0->vy = 0;
            arg0->state = 4;
        set:
            arg0->substate = 0;
            return;
        }
    }
    if (arg0->fast == 0) {
        if (arg0->facing != 0) {
            arg0->vx = 0x20000;
        } else {
            arg0->vx = -0x20000;
        }
    } else {
        if (arg0->facing != 0) {
            arg0->vx = 0x40000;
        } else {
            arg0->vx = -0x40000;
        }
    }
    move_object(arg0);
}
