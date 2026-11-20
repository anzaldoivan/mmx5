/* Shared body (DK-5), from the banked draft of func_800F8864_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];
extern s32 D_800FF1DC_ovl06[];
extern s32 D_800FF1E0_ovl06[];

void DEDUP_NAME(u8* obj) {
    u8 flags;
    s32 hit;

    animate_object(obj);
    apply_object_motion(obj);
    func_8002FB58(obj);
    flags = obj[0x70];
    if (flags & 8) {
        start_pad_vibration(5);
        func_8002A600(0x5A, 4, 2);
        play_sound(2, 7, obj);
        set_animation(obj, 0x1E);
        *(u8**)(obj + 0x50) = D_800FF1CC_ovl06;
        *(u8**)(obj + 0x54) = D_800FF1D0_ovl06;
        *(s16*)(obj + 0x7C) = 0;
        obj[6] = 5;
        return;
    }
    if (obj[0x15] == 0x40) {
        if (flags & 1) {
            goto set; // !FAKE: goto kept for the matching branch layout
        }
        hit = flags & 4;
    } else {
        hit = *(s32*)(obj + 0x70) & 6;
    }
    if (hit != 0) {
    set:
        start_pad_vibration(5);
        func_8002A600(0x5A, 4, 2);
        set_animation(obj, 0x14);
        *(s32**)(obj + 0x50) = D_800FF1DC_ovl06;
        *(s32**)(obj + 0x54) = D_800FF1E0_ovl06;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x3000;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
}
