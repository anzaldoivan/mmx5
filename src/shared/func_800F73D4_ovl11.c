/* Shared body (DK-5), from the banked draft of func_800F73D4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

extern void func_8002DED4(Obj73D4*);
extern void func_80017248(Obj73D4*);
extern void func_800171E8(Obj73D4*, s32);

void DEDUP_NAME(Obj73D4* o) {
    func_8002DED4(o);
    func_80017248(o);
    if (o->x <= D_800FA056_ovl11 - 0x18) {
        o->x = D_800FA056_ovl11 - 0x18;
    } else if (o->x >= D_800FA058_ovl11 + 0x18) {
        o->x = D_800FA058_ovl11 + 0x18;
    }
    if (o->flags & 8) {
        func_800171E8(o, 0);
        o->timer = 0x14;
        o->state = 5;
        o->unk24 = 0;
        o->unk2C = 0;
        if (o->facing == 0) {
            o->vx = -0x40000;
        } else {
            o->vx = 0x40000;
        }
        func_800171E8(o, 4);
        o->vy = -0x1999;
    }
}
