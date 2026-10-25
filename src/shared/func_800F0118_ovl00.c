/* Shared body (DK-5), from the banked draft of func_800F0118_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(ObjFE130*);
extern u8 D_800FA778_ovl00[];

void DEDUP_NAME(ObjFE130* obj) {
    if (obj->unk45 == 1) {
        obj->unk68 = D_800FA778_ovl00;
        obj->unk5 = 2;
        obj->unk6 = 0;
        D_1F80004C.scr1090->unk86 = 0x28;
    } else {
        DEDUP_CALLEE(obj);
    }
}
