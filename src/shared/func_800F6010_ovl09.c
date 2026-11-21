#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void silence_sound(s32, s32);

void func_800F6010_ovl09(Obj3DD4* o) {
    ObjFAF38* c;

    if (--o->unk7C == 0) {
        silence_sound(2, 0x26);
        c = func_8002D1A4();
        if (c != 0) {
            play_sound(2, 0x25, o);
            c->unk0 = 0x41;
            c->unk1 = 0x10;
            c->unk2 = 3;
            c->unk7C = o;
        }
        if (o->unk15 != 0) {
            o->unk20 = 0x20000;
        } else {
            o->unk20 = -0x20000;
        }
        o->unk6++;
    }
    animate_object(o);
    apply_object_motion(o);
}

extern s16 D_800FB628_ovl09;
extern s16 D_800FB62A_ovl09;

void func_800F60D0_ovl09(u8* obj) {
    if (obj[0x15] == 0) {
        if (*(s16*)(obj + 0xA) > D_800FB628_ovl09) {
            goto done; // !FAKE: early exit to the shared tail; nested if/else does not match (C0074)
        }
    } else if (*(s16*)(obj + 0xA) < D_800FB62A_ovl09) {
        goto done; // !FAKE: early exit to the shared tail; nested if/else does not match (C0074)
    }
    *(s32*)(obj + 0x20) = 0;
    *(s16*)(obj + 0x7C) = 20;
    obj[6]++;
done:
    animate_object(obj);
    apply_object_motion(obj);
}

extern u8 D_800FAD58_ovl09[][6];

void func_800F6150_ovl09(Ent6234* e) {
    if (--e->unk7C == 0) {
        u8 t;
        set_animation(e, 0);
        t = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    animate_object(e);
    apply_object_motion(e);
}
