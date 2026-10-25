/* Shared body (DK-5), from the banked draft of func_800F649C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

void func_800F5E5C_ovl04(Obj649C* o);
void func_800F6358_ovl04(Obj649C* o);

void DEDUP_NAME(Obj649C* o) {
    if (o->unk4 == 0) {
        func_800F5E5C_ovl04(o);
    } else if (o->unk7 == 0) {
        func_800F6358_ovl04(o);
    } else {
        o->unk7--;
    }
}
