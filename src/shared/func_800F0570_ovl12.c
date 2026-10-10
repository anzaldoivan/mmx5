/* Shared body (DK-5), from the banked draft of func_800F0570_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Ent*, s32);
extern void func_80017248(Ent*);
extern void func_8002DED4(Ent*);
extern s16 D_8009A0AA;

void DEDUP_NAME(Ent* obj) {
    func_800171E8(obj, 5);
    if (D_8009A0AA > obj->y) {
        obj->flag15 = 0x40;
    } else {
        obj->flag15 = 0;
    }
    obj->state++;
    func_80017248(obj);
    func_8002DED4(obj);
}
