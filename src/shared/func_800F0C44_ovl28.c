/* Shared body (DK-5), from the banked draft of func_800F0C44_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern int func_8002D6FC();
extern int func_8002D760();
extern int func_8002D7A0();

#define G D_1F80004C.bytes
void DEDUP_NAME(u8* arg0) {
    G[0x80] = 0;
    G[0x81] = 0;
    G[0x82] = 0;
    G[0x83] = 0;
    G[0x84] = 0;
    G[0x85] = 0;
    G[0x86] = 0;
    G[0x87] = 0;
    G[0x88] = 0;
    if (*(signed char*)(arg0 + 2) & 0x80) {
        func_8002D6FC();
    } else if (*(signed char*)(arg0 + 4) == 2) {
        func_8002D760();
    } else {
        func_8002D7A0();
    }
}
