/* Shared body (DK-5), from the banked draft of func_800FB984_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

#include "addr.h"

extern u8* func_8002D144(void);
extern void func_800171E8(Obj3DD4*, s32);
extern signed char D_8009A0A5;

void DEDUP_NAME(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
        func_800171E8(a, 2);
        a->unk6++;
    }
}
