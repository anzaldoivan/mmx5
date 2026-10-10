#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(Ent*, s32);

void func_800F9CF8_ovl28(Ent* e) {
    func_800171E8(e, 6);
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    e->state++;
}
