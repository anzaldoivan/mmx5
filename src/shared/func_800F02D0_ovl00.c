/* Shared body (DK-5), from the banked draft of func_800F02D0_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    u8* scr;
    s8 t;

    scr = D_1F80004C.bytes;
    if (scr[0x85] == 1) {
        *(s16*)(scr + 0x96) = 1;
    }
    switch ((s8)obj[2]) {
    case 0:
        t = obj[0x45];
        if (t == 3) {
            D_1F80004C.bytes[0x91] = 1;
            DEDUP_CALLEE(obj, 0);
            obj[5] = t;
            obj[6] = 0;
        }
        break;
    case 1:
        D_1F80004C.bytes[0x86] = 20;
        obj[5] = 2;
        obj[6] = 0;
        break;
    case 2:
        D_1F80004C.bytes[0x86] = 20;
        obj[5] = 2;
        obj[6] = 0;
        break;
    case 3:
        D_1F80004C.bytes[0x86] = 20;
        obj[5] = 2;
        obj[6] = 0;
        break;
    }
}
