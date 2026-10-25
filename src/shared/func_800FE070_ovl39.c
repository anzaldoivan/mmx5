/* Shared body (DK-5), from the banked draft of func_800FE070_ovl39 by tools/wave/gate.py rescan. */
#include "types.h"

extern EntFE070 D_8009A0A0;

extern void func_80017248(EntFE070*);
extern s32 func_800317B8(EntFE070*);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_8002DF54(EntFE070*);

void DEDUP_NAME(EntFE070* e) {
    s32 angle;

    func_80017248(e);
    func_800317B8(e);
    if (--e->timer == 0) {
        angle = ratan2(D_8009A0A0.y - e->y, D_8009A0A0.x - e->x);
        e->vx = rcos(angle) * 96;
        e->vy = -rsin(angle) * 96;
        func_8002DF54(e);
        e->state++;
    }
}
