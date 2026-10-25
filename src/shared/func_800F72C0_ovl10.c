/* Shared body (DK-5), from the banked draft of func_800F72C0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj72C0*, s32);
extern int func_8002D6FC();
extern s8 D_8009A0A2;

void DEDUP_NAME(Obj72C0* obj) {
    obj->b4 = 0xF;
    obj->b3 = 1;
    obj->b16 = 2;
    obj->w68 = 0;
    obj->w54 = 0;
    obj->w50 = 0;
    if (D_8009A0A2 != 0) {
        func_800171E8(obj, 0x1E);
    } else {
        func_800171E8(obj, 0x1C);
    }
    if (obj->parent->state == 3) {
        func_8002D6FC(obj);
    }
}
