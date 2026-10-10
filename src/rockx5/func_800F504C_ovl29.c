#include "types.h"

extern s16 D_8009A0AA;
extern s32 D_800F9898_ovl29[];
extern void func_800171E8(Obj4EA0*, s32);

void func_800F504C_ovl29(Obj4EA0* e) {
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    func_800171E8(e, 9);
    e->unk50 = D_800F9898_ovl29;
    e->unk6++;
}
