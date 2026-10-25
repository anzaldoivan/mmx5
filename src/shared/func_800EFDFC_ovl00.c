/* Shared body (DK-5), from the banked draft of func_800EFDFC_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_800FA78C_ovl00[];

void DEDUP_NAME(u8* arg0) {
    D_1F80004C.bytes[0x91] = 1;
    arg0[6]++;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    if (*(s8*)(arg0 + 2) == 0 && D_1F80004C.bytes[0x85] == 1) {
        *(u8**)(arg0 + 0x54) = D_800FA78C_ovl00;
    }
}
