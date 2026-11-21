#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

extern void func_800F81F4_ovl11(u8* obj);
extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void func_800F6FA0_ovl11(u8* obj) {
    u8* p;
    s16 x;

    set_animation(obj, 5);
    animate_object(obj);
    obj[0x60] = 8;
    p = g_Player;
    if (((s8*)p)[2] == 0 && p[0xFA] == 0) {
        obj[0x62] = 8;
    } else {
        obj[0x62] = 6;
    }
    func_800F81F4_ovl11(obj);
    x = *(s16*)(obj + 0xA);
    if (x < D_800FA056_ovl11) {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 1;
    } else if (D_800FA058_ovl11 < x) {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = -1;
    }
    *(s32*)(obj + 0x28) = -0x3333;
    *(s16*)(obj + 0x7C) = 8;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) <<= 18;
    obj[6]++;
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_80050650(s32, s16, s16, s16, s16, s32);

#define S16(p, o) (*(s16*)((p) + (o)))
#define S32(p, o) (*(s32*)((p) + (o)))
void func_800F7094_ovl11(u8* obj) {
    if (!(D_8009A420_as_s32 & 1)) {
        func_80050650(0x11, S16(obj, 0xA) - 0x10, S16(obj, 0xE) + 0x28,
                      S16(obj, 0xA) + 0x10, S16(obj, 0xE) + 0x28, 1);
    }
    apply_object_motion(obj);
    animate_object(obj);
    if ((S32(obj, 0x20) < 0 ? -S32(obj, 0x20) : S32(obj, 0x20)) < 0x4000) {
        set_animation(obj, 0);
        obj[0x62] = 0;
        S16(obj, 0x7C) = 0x1E;
        obj[6]++;
    }
}
