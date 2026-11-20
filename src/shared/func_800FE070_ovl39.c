/* Shared body (DK-5), from the banked draft of func_800FE070_ovl39 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define g_Player_as_EntFE070 (*(EntFE070*)&g_Player)

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void DEDUP_NAME(EntFE070* e) {
    s32 angle;

    animate_object(e);
    func_800317B8(e);
    if (--e->timer == 0) {
        angle = ratan2(g_Player_as_EntFE070.y - e->y,
                       g_Player_as_EntFE070.x - e->x);
        e->vx = rcos(angle) * 96;
        e->vy = -rsin(angle) * 96;
        move_object(e);
        e->state++;
    }
}
