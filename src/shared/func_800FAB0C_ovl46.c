/* Shared body (DK-5), from the banked draft of func_800FAB0C_ovl46 by tools/wave/gate.py rescan. */
#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern u8 D_80091C44;
extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);

void DEDUP_NAME(UnkObj* e) {
    if (--e->unk6 == 0) {
        D_8009A1F8.unkB6 += 0x100;
        if ((s16)D_8009A1F8.unkB6 >= 0x300) {
            D_8009A1F8.unkB6 = 0;
        }
        e->unk6 = 0x3C;
    }
    D_8009A1F8.unkF4 = 1;
    if (D_80091C44 == 0) {
        func_800132F8(8);
        func_80017E54(3);
        e->unk1++;
    }
}
