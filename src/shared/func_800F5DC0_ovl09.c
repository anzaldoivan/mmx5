#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void silence_sound(s32, s32);

void func_800F5DC0_ovl09(Obj3DD4* o) {
    ObjFAF38* c;

    if (--o->unk7C == 0) {
        silence_sound(2, 0x26);
        c = func_8002D1A4();
        if (c != 0) {
            play_sound(2, 0x25, o);
            c->unk0 = 0x41;
            c->unk1 = 0x10;
            c->unk2 = 2;
            c->unk7C = o;
        }
        o->unk24 = -0x18000;
        o->unk6++;
    }
    animate_object(o);
    apply_object_motion(o);
}

extern s16 D_800FB626_ovl09;

void func_800F5E70_ovl09(u8* obj) {
    if (*(s16*)(obj + 0xE) >= D_800FB626_ovl09) {
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 20;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F5ED0_ovl09(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s32*)(obj + 0x24) = 0x30000;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FB61E_ovl09;
extern u8 D_800FAD58_ovl09[][6];

void func_800F5F2C_ovl09(Ent5F2C* e) {
    if (e->unkE <= D_800FB61E_ovl09) {
        e->unkE = D_800FB61E_ovl09;
        e->unk24 = 0;
        e->unk5 = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
    }
    animate_object(e);
    apply_object_motion(e);
}
