#include "types.h"

extern s16 D_800FA64A_ovl29;
extern void func_800171E8(Ent*, s32);

void func_800F49FC_ovl29(Ent* e) {
    if (e->y > D_800FA64A_ovl29) {
        e->flag15 = 0;
    } else {
        e->flag15 = 0x40;
    }
    func_800171E8(e, 0xA);
    e->state++;
}
