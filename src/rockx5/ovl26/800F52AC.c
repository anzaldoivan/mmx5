#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

void func_800F52AC_ovl26(u8* obj) {
    animate_object(obj);
    set_animation(obj, 0x11);
    obj[6]++;
}

extern u8 D_800F9620_ovl26[];
extern u8 D_800F962C_ovl26[];

void func_800F52E8_ovl26(u8* p) {
    animate_object(p);
    if (*(s8*)(p + 0x45) == 1) {
        *(s32*)(p + 0x2C) = 0x1000;
        *(s32*)(p + 0x24) = 0;
        p[0x60] = 0x18;
        *(u8**)(p + 0x68) = D_800F9620_ovl26;
        *(u8**)(p + 0x50) = D_800F962C_ovl26;
        p[6]++;
    }
}

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);

void func_800F5350_ovl26(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        start_pad_vibration(5);
        play_sound(2, 0x63, obj);
        func_8002A600(0x1E, 4, 1);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x30000;
        } else {
            *(s32*)(obj + 0x20) = -0x30000;
        }
        obj[6]++;
        set_animation(obj, 0x13);
    }
}

extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_800F9F04_ovl26[];
extern u8 D_8009A244;

void func_800F53E8_ovl26(u8* obj) {
    u8* p;

    animate_object(obj);
    move_object(obj);
    if (obj[0x70] & 3) {
        play_sound(2, 0x63, obj);
        p = D_800F9F04_ovl26;
        func_80028B18(0, 0x8B0, 0x11D0, p);
        func_80028B18(0, 0xA60, 0x11D0, p + 8);
        D_8009A244 = 1;
        set_animation(obj, 0x12);
        func_8002A5C4(0x32, 8, 1);
        *(s16*)(obj + 0x7C) = 0x5A;
        obj[6]++;
    }
}

extern u8 D_800F9F14_ovl26[];
extern u8 D_8009A244;

void func_800F54A8_ovl26(u8* obj) {
    u8* p;

    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        p = D_800F9F14_ovl26;
        func_80028B18(0, 0x8B0, 0x11D0, p);
        func_80028B18(0, 0xA60, 0x11D0, p + 8);
        D_8009A244 = 1;
        obj[5] = 0xB;
        obj[6] = 0;
        *(s16*)(obj + 0x7E) = 3;
    }
}

#define D_800EEC60_ovl00 func_800F553C_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
