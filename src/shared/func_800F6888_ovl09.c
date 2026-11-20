/* Shared body (DK-5), from the banked draft of func_800F6888_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x7C);
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    if (*(s8*)(obj + 5) == 0) {
        if (*(s32*)(p + 0x20) == 0) {
            set_animation(obj, 1);
            obj[5] = 1;
        }
    } else if (*(s32*)(p + 0x24) == 0) {
        set_animation(obj, 0);
        obj[5] = 0;
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4]++;
    }
    func_8002D9EC(obj, 0x10, 0x10);
    animate_object(obj);
    apply_object_motion(obj);
}
