#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/sound.h"
#include "mmx5/ovl06.h"

extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void func_800FA858_ovl06(Obj0364* o) {
    animate_object(o);
    if (o->mode == 1) {
        set_animation(o, 0x1C);
        o->p50 = D_800FF1CC_ovl06;
        o->p54 = D_800FF1D0_ovl06;
        o->timer = 0x30;
        o->h7E = 0;
        D_1F80004C.scr01a8->unk8A = 0;
        o->state++;
    }
}

void func_800FA8D8_ovl06(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x20, obj);
        obj[6]++;
    }
}

extern void func_800FAF38_ovl06(u8*, s32, s32, s32);

void func_800FA928_ovl06(u8* obj) {
    s32 t;

    animate_object(obj);
    t = *(s16*)(obj + 0x7C);
    if (t == 0) {
        set_animation(obj, 0x1D);
        obj[6]++;
        return;
    }
    t = *(u16*)(obj + 0x7C);
    if (!(t & 1)) {
        func_800FAF38_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE),
                            (u8)(obj[0x7E] + 0x20));
        if (D_1F80004C.bytes[0x8A] & 1) {
            (*(u16*)(obj + 0x7E))++;
        }
        D_1F80004C.bytes[0x8A]++;
    }
    (*(u16*)(obj + 0x7C))--;
}

void func_800FAA00_ovl06(u8* obj) {
    D_1F80004C.bytes[0x8A] = 0;
    animate_object(obj);
    func_800F9180_ovl06(obj);
}
