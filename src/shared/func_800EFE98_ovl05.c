/* Shared body (DK-5), from the banked draft of func_800EFE98_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        ((s32(*)())func_8004FD90)(obj, 1, 0x20, 0x10);
        obj->unk7E = 5;
    }
}
