/* Shared body (DK-5), from the banked draft of func_800F0110_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002FB58(Ent0110*);
extern s32 func_80031DD0(Ent0110*);
extern s32 func_800317B8(Ent0110*);
extern void func_8002D89C(Ent0110*);
extern u8 D_8009A197;
extern void (*D_800FB474_ovl10[])(Ent0110*);
extern s32 D_800FB45C_ovl10[];

void DEDUP_NAME(Ent0110* self) {
    func_8002FB58(self);
    if (D_8009A197 == 0) {
        D_800FB474_ovl10[self->state](self);
    }
    self->animPtr = self->animBase = &D_800FB45C_ovl10[self->anim];
    func_80031DD0(self);
    func_800317B8(self);
    func_8002D89C(self);
}
