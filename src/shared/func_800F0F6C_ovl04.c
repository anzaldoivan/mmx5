/* Shared body (DK-5), from the banked draft of func_800F0F6C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    apply_object_motion(obj);
    ((s32(*)())func_8002FB58)(obj);
    if (obj[0x70] & 8) {
        D_1F80004C.bytes[0x82] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 0;
        if (D_1F80004C.bytes[0x80] == 0) {
            obj[5] = 4;
        } else {
            obj[5] = 5;
        }
        obj[6] = 0;
    }
}
