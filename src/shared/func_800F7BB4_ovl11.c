/* Shared body (DK-5), from the banked draft of func_800F7BB4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800F81F4_ovl11(u8* obj);

s32 DEDUP_NAME(u8* obj) {
    s32 ret;
    obj[0x60] = 8;
    obj[0x62] = 0;
    *(s32*)(obj + 0x68) = 0;
    set_animation(obj, 1);
    animate_object(obj);
    func_800F81F4_ovl11(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x40000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
    ret = play_sound(2, 0x32, obj);
    obj[0x9A] = 1;
    return ret;
}
