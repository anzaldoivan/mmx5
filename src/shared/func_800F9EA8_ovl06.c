#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern u8 D_800FF1E4_ovl06[];
extern u8 D_800FF1E8_ovl06[];

void func_800F9EA8_ovl06(u8* arg0) {
    set_animation(arg0, 0xA);
    *(u8**)(arg0 + 0x50) = D_800FF1E4_ovl06;
    *(u8**)(arg0 + 0x54) = D_800FF1E8_ovl06;
    *(s16*)(arg0 + 0x7C) = 1;
    *(s16*)(arg0 + 0x7E) = (random_byte() & 1) + 3;
    arg0[6]++;
}

extern void func_800FAF38_ovl06(u8*, s32, s32, s32);
extern u8 D_800FF1DC_ovl06[];
extern u8 D_800FF1E0_ovl06[];

void func_800F9F0C_ovl06(u8* obj) {
    s8 state;

    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 10);
        *(u16*)(obj + 0x7C) = 40;
    }
    state = *(s8*)(obj + 0x45);
    if (state == 2) {
        play_sound(2, 0x1F, obj);
        func_800FAF38_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 1);
    } else if (state == 3) {
        if (--*(s16*)(obj + 0x7E) == 0) {
            set_animation(obj, 20);
            *(u8**)(obj + 0x50) = D_800FF1DC_ovl06;
            *(u8**)(obj + 0x54) = D_800FF1E0_ovl06;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0x3000;
            obj[6]++;
        }
    }
}
