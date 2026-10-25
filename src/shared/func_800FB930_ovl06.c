/* Shared body (DK-5), from the banked draft of func_800FB930_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(ObjFB930*);
extern s32 func_8002D938(ObjFB930*, s32, s32);
extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void DEDUP_NAME(ObjFB930* obj) {
    func_8002DED4(obj);
    if (func_8002D938(obj, 0x50, 0x50) == 0) {
        if (obj->kind == 11) {
            obj->p50 = D_800FF684_ovl06;
            obj->p54 = D_800FF688_ovl06;
        }
    } else {
        obj->state = 2;
    }
}
