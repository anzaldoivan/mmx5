#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "addr.h"

void func_800F2448_ovl00(Obj* o) {
    set_animation(o, 1);
    o->timer = 0x14;
    o->step++;
}

void func_800F2484_ovl00(Obj800EFBC4* o) {
    s32 vx;

    if (--o->unk7C == -1) {
        set_animation(o, 4);
        vx = -0x28000;
        if (o->unk15) {
            vx = 0x28000;
        }
        o->unk20 = vx;
        o->unk24 = 0;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk6++;
    }
}

void func_800F2504_ovl00(u8* a0) {
    s32 v;

    if (a0[0x15] == 0) {
        v = a0[0x70] & 2;
    } else {
        v = a0[0x70] & 1;
    }
    if (v) {
        *(s16*)(a0 + 0x7C) = 0x3C;
        a0[6]++;
    } else {
        move_object(a0);
    }
}

extern void silence_sound(s32, s32);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800FAC8C_ovl00[];

void func_800F2568_ovl00(u8* a0) {
    if (--*(s16*)(a0 + 0x7C) == 0) {
        silence_sound(2, 0xF);
        func_8004D4F4(4, D_800FAC8C_ovl00, a0);
        a0[3] = 0;
        *(s16*)(a0 + 0x7C) = 0x19;
        *(s16*)(a0 + 0x7E) = 5;
        D_1F80004C.bytes[0x87] = 0;
        a0[4] = 6;
    }
}
