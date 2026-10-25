/* Shared body (DK-5), from the banked draft of func_800F50E8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80074EE0[];
extern void (*D_800FBE7C_ovl10[])(u8*);

void DEDUP_NAME(u8* arg0) {
    *(u8**)(arg0 + 0x58) = D_80074EE0;
    D_800FBE7C_ovl10[*(signed char*)(arg0 + 6)](arg0);
}
