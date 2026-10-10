#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(Ent*, s32);

void func_800F47EC_ovl29(Ent* e) {
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    func_800171E8(e, 0xC);
    e->state++;
}
