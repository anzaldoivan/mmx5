/* Shared body (DK-5), from the banked draft of func_800F6E38_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern int func_8002D6FC();

void DEDUP_NAME(u8* obj) {
    if (obj[0x8F] != 0) {
        obj[0x8F]--;
        func_80017248(obj);
    } else {
        func_8002D6FC(obj);
    }
}
