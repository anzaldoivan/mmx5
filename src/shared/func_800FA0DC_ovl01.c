#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FD578_ovl01[];
extern u8 D_800FD57C_ovl01[];
extern u8 D_800FD5A8_ovl01[];
extern u8 D_800FD5AC_ovl01[];

void func_800FA0DC_ovl01(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) < 0) {
        start_pad_vibration(5);
        play_sound(2, 7, obj);
        set_animation(obj, 0xF);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0x28;
        func_8002A600(0x1E, 4, 2);
        obj[6] = 2;
    }
    if (obj[0x47] == 9) {
        *(u8**)(obj + 0x54) = D_800FD5AC_ovl01;
        *(u8**)(obj + 0x50) = D_800FD5A8_ovl01;
    } else {
        *(u8**)(obj + 0x54) = D_800FD578_ovl01;
        *(u8**)(obj + 0x50) = D_800FD57C_ovl01;
    }
}

void func_800FA1B0_ovl01(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        obj[5] = 3;
        obj[6] = 0;
    }
}
