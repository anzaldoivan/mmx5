/* Shared body (DK-5), from the banked draft of func_800F7458_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    if (obj[0x47] == 0xAA || obj[0x47] == 0xAB) {
        obj[0x16] = 2;
    } else {
        obj[0x16] = 5;
    }
    animate_object(obj);
    func_8002D89C(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        clear_object_slot(obj);
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 3) {
        clear_object_slot(obj);
    }
}
