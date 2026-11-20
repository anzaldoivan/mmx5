/* Shared body (DK-5), from the banked draft of func_800F5BF8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A0B5;

void DEDUP_NAME(u8* obj) {
    func_8003D29C(0x14, D_8009A0B5);
    obj[5]++;
    set_animation(obj, 0x1C);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x89] = 0x19;
    animate_object(obj);
    func_8002D89C(obj);
}
