/* Shared body (DK-5), from the banked draft of func_800FC254_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800FC9E0_ovl07(EntFC254*);
extern void func_800171E8(EntFC254*, s32);
extern void func_800FCB98_ovl07(EntFC254*, s32, s32, s32);

void DEDUP_NAME(EntFC254* e) {
    s16 t;

    func_800FC9E0_ovl07(e);
    func_800171E8(e, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(e, e->x, e->y, 2);
    switch (e->kind) {
    case 6:
        t = 0x28;
        break;
    case 12:
        t = 0x50;
        break;
    case 13:
        t = 0x78;
        break;
    case 14:
        t = 0xA0;
        break;
    default:
        goto end; // !FAKE: skips the timer store, as the target branches to the tail
    }
    e->timer = t;
end:
    e->step++;
}
