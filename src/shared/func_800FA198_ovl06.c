#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/ovl06.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FF1EC_ovl06[];
extern u8 D_800FF1F0_ovl06[];

void func_800FA198_ovl06(u8* obj) {
    u8* p;
    s32 a;
    s32 t;
    s32 y;
    s32 x;

    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0xF);
        play_sound(2, 0x21, obj);
        *(u8**)(obj + 0x50) = D_800FF1EC_ovl06;
        *(u8**)(obj + 0x54) = D_800FF1F0_ovl06;
        p = g_Player;
        x = *(s16*)(p + 0xA);
        y = *(s16*)(p + 0xE);
        a = ratan2(*(s16*)(obj + 0xE) - y, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        t = rcos(a) * 16;
        *(s32*)(obj + 0x20) = t * 6;
        t = rsin(a) * 16;
        *(s32*)(obj + 0x24) = t * 6;
        obj[6]++;
    }
}

extern void start_pad_vibration(s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void func_800FA284_ovl06(ObjFA284* o) {
    o->timer++;
    animate_object(o);
    apply_object_motion(o);
    ((s32(*)())func_8002FB58)(o);
    if (o->flags70 & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, o);
        set_animation(o, 0x15);
        o->p50 = D_800FF1CC_ovl06;
        o->p54 = D_800FF1D0_ovl06;
        o->step++;
    }
}

void func_800FA324_ovl06(u8* obj) {
    animate_object(obj);
    if (++*(s16*)(obj + 0x7C) >= 90) {
        func_800F9180_ovl06(obj);
    }
}
