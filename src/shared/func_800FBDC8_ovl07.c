/* Shared body (DK-5), from the banked draft of func_800FBDC8_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    u8* p;

    animate_object(obj);
    move_object(obj);
    p = D_1F80004C.bytes;
    if (*(s16*)(p + 0x84) >= *(s16*)(obj + 0xE)) {
        p[0x92] = 0;
        obj[5] = 3;
        obj[6] = 0;
    }
}
