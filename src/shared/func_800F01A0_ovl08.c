/* Shared body (DK-5), from the banked draft of func_800F01A0_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016D54(s32, s32);
extern void func_800171E8(Obj01A0*, s32);
extern void func_80017248(Obj01A0*);
extern void func_8002DF54(Obj01A0*);
extern s32 func_8002DF78(void);
extern u8 D_8009A0A0[];
extern s16 D_8009A0AA;

#define ABS(x) ((x) < 0 ? -(x) : (x))

void DEDUP_NAME(Obj01A0* arg0) {

    arg0->timer8C--;
    if (arg0->timer8C == 0) {
        if (arg0->facing == 0 ? D_8009A0AA < arg0->x : D_8009A0AA > arg0->x) {
            func_800171E8(arg0, 3);
            arg0->vx = 0;
            func_80016D54(2, 0x51);
            arg0->state = 5;
            goto set; // !FAKE: state changes share the target's single set tail
        }
    }
    if (--arg0->timer82 == 0) {
        arg0->timer82 = 30;
        if ((func_8002DF78() & 7) < 5U) {
            arg0->timer7C = 10;
            arg0->vx = 0;
            arg0->state = 7;
            goto set; // !FAKE: state changes share the target's single set tail
        }
    }
    if (arg0->timer89 != 0) {
        arg0->timer89--;
    }
    func_80017248(arg0);
    if (arg0->fast == 0) {
        if (ABS(((Player01A0*)D_8009A0A0)->y - arg0->y) < 0x31) {
            if (arg0->facing == 0) {
                if (arg0->posX - ((Player01A0*)D_8009A0A0)->posX > 0x3FFFF) {
                    arg0->fast = 1;
                    func_800171E8(arg0, 7);
                }
            } else if (((Player01A0*)D_8009A0A0)->posX - arg0->posX > 0x3FFFF) {
                arg0->fast = 1;
                func_800171E8(arg0, 7);
            }
        }
    } else {
        if (ABS(((Player01A0*)D_8009A0A0)->posX - arg0->posX) <= 0x3FFFF) {
            arg0->fast = 0;
            func_800171E8(arg0, 1);
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
        if (arg0->facing == 0 ? ((PlayerA01A0*)D_8009A0A0)->x > arg0->x
                              : ((PlayerA01A0*)D_8009A0A0)->x < arg0->x) {
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
    func_8002DF54(arg0);
}
