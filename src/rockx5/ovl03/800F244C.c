#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

void func_800F244C_ovl03(u8* p) {
    s32 n;
    s32 x;
    s32 y;
    s32 d;

    n = (random_byte() & 7) << 4;
    y = D_8009A0AA;
    x = *(s16*)(p + 0xA);
    d = y - x;
    if ((d >= 0) ? (d <= n) : (x - y <= n)) {
        *(s32*)(p + 0x2C) = 0x1000;
        p[6]++;
    }
}

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void func_800F24C4_ovl03(u8* obj) {
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6] = 2;
        play_sound(5, 0x26, 0);
        if (((s8*)obj)[2] != 1) {
            func_8005019C(0x21, 2, obj, 0x18, 3);
            func_8005019C(0x22, 2, obj, 0x18, 3);
        }
    }
}

#define D_800EEC60_ovl00 func_800F2558_ovl03
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
