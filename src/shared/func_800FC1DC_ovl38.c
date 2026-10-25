/* Shared body (DK-5), from the banked draft of func_800FC1DC_ovl38 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj);
extern void (*D_800FD920_ovl38[])(u8* obj);

void DEDUP_NAME(u8* obj) {
    (*(u16*)(D_1F80004C.bytes + 0x84))++;
    D_800FD920_ovl38[*(signed char*)(obj + 6)](obj);
    DEDUP_CALLEE(obj);
}
