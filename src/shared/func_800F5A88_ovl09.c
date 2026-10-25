/* Shared body (DK-5), from the banked draft of func_800F5A88_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern void func_800171E8(Obj5A88*, s32);
extern s8 func_8002E024(Obj5A88*, u8*);
extern void func_80017248(Obj5A88*);
extern void func_8002DED4(Obj5A88*);

void DEDUP_NAME(Obj5A88* obj) {
    s8 v;

    if (--obj->timer == 0) {
        func_800171E8(obj, 4);
        v = func_8002E024(obj, D_8009A0A0);
        obj->unk92 = v;
        if ((u8)v < 9) {
            obj->unk92 = 0x1F;
        } else if ((u8)(v - 9) < 8) {
            obj->unk92 = 0x11;
        }
        obj->unk84 = 0;
        obj->unk88 = 0x2000;
        obj->timer = 0;
        obj->state++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
