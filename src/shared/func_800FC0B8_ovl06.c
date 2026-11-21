#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern void (*D_800FF748_ovl06[])(ObjFAF30*, ObjFAF30*);

static inline void inl_800FC108(ObjFAF30* a, ObjFAF30* p) {
    if (p->unk9A != 0) {
        if (p->unk9A > 0) {
            a->unk3 = 1;
            a->unk54 = 10;
            a->unk56 = 8;
            a->unk58 = (5 - a->unk2) * 2;
            a->unk8 = p->unk8;
            a->unkC = p->unkC;
            a->unk5 = 1;
            a->pad6[0] = 0;
        } else {
            p->unk9A = 0;
        }
    }
}

void func_800FC0B8_ovl06(ObjFAF30* a) {
    ObjFAF30* p = a->unk50;

    a->unk47 = p->unk47;
    a->unk15 = p->unk15;
    a->unk38 = p->unk38;
    a->unk3C = p->unk3C;
    a->unk18 = a->unk8;
    a->unk1C = a->unkC;
    if (a->unk5 == 0) {
        inl_800FC108(a, p);
    } else if (p->unk9A == 0) {
        a->unk3 = 0;
        a->unk5 = 0;
    } else {
        D_800FF748_ovl06[(s8)a->pad6[0]](a, p);
    }
}

void func_800FC1C0_ovl06(EntFC1C0* obj) {
    s32 state;

    func_8002D9EC(obj, 0x30, 0x30);
    state = obj->state;
    if (state == 0) {
        obj->unk3 = 0;
        if (obj->timer == 0) {
            play_sound(2, 0x18, obj);
            obj->state++;
        }
        obj->timer--;
    } else if (state == 1) {
        ((s32(*)())animate_object)(obj);
        if (obj->unk45 == state) {
            obj->unk4 = 2;
        }
    }
}

extern void (*D_800FF744_ovl06[])(Fc26cObj*);

void func_800FC26C_ovl06(Fc26cObj* o) {
    Fc26cObj* p = o->unk50;

    o->unkA = p->unkA;
    o->unkE = p->unkE;
    o->unk15 = p->unk15;
    o->unk42 &= 0x7FFF;
    o->unk42 |= p->unk42 & 0x8000;
    D_800FF744_ovl06[o->unk6](o);
}
