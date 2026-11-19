/* Shared body (DK-5), from the banked draft of func_800EFA38_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0x20000;
    move_object(obj);
    animate_object(obj);
}
