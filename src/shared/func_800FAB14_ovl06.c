#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl06.h"

extern void start_pad_vibration(s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void func_800FAB14_ovl06(ObjFA284* o) {
    apply_object_motion(o);
    func_8002FB58(o);
    animate_object(o);
    if (o->flags70 & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, o);
        set_animation(o, 0x15);
        o->p50 = D_800FF1CC_ovl06;
        o->p54 = D_800FF1D0_ovl06;
        o->timer = 0x3C;
        o->step++;
    }
}

extern u8 D_800FF1D4_ovl06[];
extern u8 D_800FF1D8_ovl06[];

void func_800FABAC_ovl06(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(u8*)(obj + 0x9A) = 1;
        set_animation(obj, 0x19);
        *(void**)(obj + 0x50) = D_800FF1D4_ovl06;
        *(void**)(obj + 0x54) = D_800FF1D8_ovl06;
        if (*(u8*)(obj + 0x15) == 0) {
            *(s32*)(obj + 0x20) = -0x60000;
        } else {
            *(s32*)(obj + 0x20) = 0x60000;
        }
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(u16*)(obj + 0x7C) = 1;
        *(u16*)(obj + 0x7E) = 0;
        play_sound(2, 0x22, obj);
        obj[6]++;
    }
}

void func_800FAC64_ovl06(u8* arg0) {
    s16 count;

    count = *(s16*)(arg0 + 0x7E);
    if (count == 0 || count - 1 == D_1F80004C.bytes[0x8B]) {
        arg0[6]++;
    }
}

void func_800FACAC_ovl06(u8* obj) {
    animate_object(obj);
    D_1F80004C.bytes[0x8B] = 0;
    D_1F80004C.bytes[0x8A] = 0;
    func_800F9180_ovl06(obj);
}
