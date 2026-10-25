/* Shared body (DK-5), from the banked draft of func_800F0C98_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* e) {
    if (*(s8*)(e + 4) == 1 && D_1F80004C.bytes[0x85] == 0) {
        *(s16*)(D_1F80004C.bytes + 0x96) = 0;
        if (--D_1F80004C.bytes[0x92] == 0xFF) {
            *(s32*)(D_1F80004C.bytes + 0x88) = 0;
            D_1F80004C.bytes[0x87] = 0;
            e[5] = 4;
            e[6] = 0;
            D_1F80004C.bytes[0x92] = 0x32;
        }
    }
}
