/* Shared body (DK-5), from the banked draft of func_800FC1C0_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002D9EC(EntFC1C0*, s32, s32);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_80017248(EntFC1C0*);

void DEDUP_NAME(EntFC1C0* obj) {
    s32 state;

    func_8002D9EC(obj, 0x30, 0x30);
    state = obj->state;
    if (state == 0) {
        obj->unk3 = 0;
        if (obj->timer == 0) {
            func_80016490(2, 0x18, obj);
            obj->state++;
        }
        obj->timer--;
    } else if (state == 1) {
        func_80017248(obj);
        if (obj->unk45 == state) {
            obj->unk4 = 2;
        }
    }
}
