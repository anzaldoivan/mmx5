/* Shared body (DK-5), from the banked draft of func_800EFCD8_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern int func_8002D7A0();
extern int func_8002D760();

void DEDUP_NAME(void) {
    if (--D_1F80004C.ctx800efcd8->unk94 == 0xFFFF) {
        if (D_1F80004C.ctx800efcd8->unk93) {
            func_8002D7A0();
        } else {
            func_8002D760();
        }
    }
}
