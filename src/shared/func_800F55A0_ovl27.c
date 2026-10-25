/* Shared body (DK-5), from the banked draft of func_800F55A0_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800F5C58_ovl27(Obj5524*);
extern void func_800F59D8_ovl27(Obj5524*);
extern void func_800171E8(Obj5524*, s32);

void DEDUP_NAME(Obj5524* obj) {
    u8* sp;

    if (--obj->timer7E == 0) {
        obj->timer7E = 0x28;
        func_800F5C58_ovl27(obj);
    }
    if (--obj->timer7C == 0) {
        sp = D_1F80004C.bytes;
        if (sp[0x87] == 0) {
            func_800F59D8_ovl27(obj);
        } else {
            sp[0x86] = 0;
            func_800171E8(obj, 1);
            obj->state6++;
        }
    }
}
