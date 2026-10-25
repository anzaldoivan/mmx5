/* Shared body (DK-5), from the banked draft of func_800F5C0C_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(Obj5C0C*, s32);
extern void func_8002D9EC(Obj5C0C*, s32, s32);
extern void func_80017248(Obj5C0C*);
extern void func_8002DED4(Obj5C0C*);

void DEDUP_NAME(Obj5C0C* e) {
    func_800171E8(e, 3);
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk7C = 0;
    e->unk6++;
    func_8002D9EC(e, 0x40, 0x40);
    func_80017248(e);
    func_8002DED4(e);
}
