/* Shared body (DK-5), from the banked draft of func_800FA6BC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern void func_800FB418_ovl01(s32, void*, u8*, s32);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FD9CC_ovl01[];

void DEDUP_NAME(u8* obj) {
    u16 x;

    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        start_pad_vibration(5);
        *(s32*)(obj + 0x68) = 0;
        func_800FB418_ovl01(0x1E, D_800FD9CC_ovl01, obj, 2);
        x = *(u16*)(obj + 0xA);
        func_80050650(0x21, x - 0x50, *(s16*)(obj + 0xE), x + 0x50,
                      *(u16*)(obj + 0xE) + 0x80, 6);
        play_sound(2, 0xC, obj);
        func_8002A600(0x28, 4, 2);
        set_animation(obj, 0xA);
        obj[6] = 5;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
}
