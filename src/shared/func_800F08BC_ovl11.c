/* Shared body (DK-5), from the banked draft of func_800F08BC_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern void func_80054440(u8* a0, s32 a1);

void DEDUP_NAME(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        func_80054440((u8*)obj, 8);
        obj->unk4++;
    } else if (--obj->unk7E == 0) {
        func_8004FD90(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
