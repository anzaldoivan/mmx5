/* Shared body (DK-5), from the banked draft of func_800F0F0C_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    if (**(s8**)(obj + 0x80) == 0) {
        if (*(s8*)(obj + 2) == 0) {
            func_8002385C(0x34, 0xFF, 0);
        } else {
            func_8002385C(0x36, 0xFF, 0);
        }
        obj[5]++;
    }
    func_8002D9EC(obj, 0x40, 0x40);
}
