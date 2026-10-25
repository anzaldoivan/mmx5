/* Shared body (DK-5), from the banked draft of func_800F3560_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(Obj3560*);
extern void func_8002D89C(Obj3560*);
extern void func_80017248(Obj3560*);

void DEDUP_NAME(Obj3560* obj) {
    s8 state = obj->unk7;
    s8 t;

    if (state == 0) {
        func_800317B8(obj);
        func_8002D89C(obj);
        func_80017248(obj);
        t = obj->unk45;
        if (t == 1) {
            obj->unk50 = 0;
        } else if (t == 2) {
            obj->unk50 = 0;
            obj->unk7++;
        }
    } else if (state == 1) {
        func_8002D89C(obj);
        t = obj->unk46;
        if (t < 0) {
            obj->unk4 = 3;
        } else {
            func_80017248(obj);
        }
    }
}
