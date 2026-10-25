/* Shared body (DK-5), from the banked draft of func_800F7334_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;
extern void func_8002DF54(Ent7334*);
extern void func_80017248(Ent7334*);
extern void func_800171E8(Ent7334*, s32);

void DEDUP_NAME(Ent7334* e) {
    if (e->x < D_800FA056_ovl11) {
        e->x += 2;
    } else if (D_800FA058_ovl11 < e->x) {
        e->x -= 2;
    }
    func_8002DF54(e);
    func_80017248(e);
    if (--e->timer == 0) {
        func_800171E8(e, 2);
        e->timer = 90;
        e->state++;
    }
}
