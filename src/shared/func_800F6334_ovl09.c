/* Shared body (DK-5), from the banked draft of func_800F6334_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void silence_sound(s32, s32);
extern u8 D_800FAB9C_ovl09[];
extern u8 D_800FABA4_ovl09[];

void DEDUP_NAME(u8* obj) {
    silence_sound(2, 0x26);
    set_animation(obj, 2);
    *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
    *(u8**)(obj + 0x54) = D_800FABA4_ovl09;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x8000;
    obj[6]++;
    animate_object(obj);
    apply_object_motion(obj);
}
