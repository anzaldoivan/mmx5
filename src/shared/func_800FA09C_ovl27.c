/* Shared body (DK-5), from the banked draft of func_800FA09C_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern s32 func_8003D2C4(void);
extern signed char D_800D1CA2;

void DEDUP_NAME(EntBD40* obj) {
    if (--obj->unk7C == 0) {
        func_80016490(0, 0xE, 0);
        obj->unk7C = 2;
    }
    if (++obj->unk5C >= D_800D1CA2) {
        func_8003D2C4();
        obj->unk6++;
    }
}
