/* Shared body (DK-5), from the banked draft of func_800FBA68_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FF6AC_ovl06[];
extern u8 D_800FF6B0_ovl06[];

void DEDUP_NAME(Obj800FBA68* obj) {
    switch (obj->unk47) {
    case 0x4E:
        obj->unk50 = D_800FF6AC_ovl06;
        break;
    case 0x51:
        obj->unk50 = D_800FF6B0_ovl06;
        break;
    case 0x53:
        obj->unk50 = 0;
        break;
    }
    if (obj->unk45 == 1) {
        obj->unk7C->unk8B = obj->unk2 & 0xF;
        obj->unk4 = 2;
    }
}
