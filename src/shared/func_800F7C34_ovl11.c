/* Shared body (DK-5), from the banked draft of func_800F7C34_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern s16 D_800FA060_ovl11;

void DEDUP_NAME(u8* obj) {
    u32 r;

    move_object(obj);
    animate_object(obj);
    if (*(s16*)(obj + 0xE) < D_800FA060_ovl11) {
        D_1F80004C.bytes[0x92] = 7;
        set_animation(obj, 2);
        *(s16*)(obj + 0x7C) = 0x5A;
        r = random_byte();
        obj[6]++;
        *(s16*)(obj + 0x7E) = (u8)(r % 3) + 4;
    }
}
