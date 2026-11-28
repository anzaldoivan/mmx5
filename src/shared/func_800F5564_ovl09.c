#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

void func_800F5564_ovl09(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE == 0x1F) {
            *(s16*)(arg0 + 0x7C) = 0xB4;
            *(s16*)(arg0 + 0x7E) = 0;
            arg0[6]++;
        }
    }
}

void func_800F5608_ovl09(Obj3DD4* o) {
    ObjFAF38* c;

    if (++o->unk7E == 10) {
        c = func_8002D1A4();
        if (c != 0) {
            c->unk0 = 0x41;
            c->unk1 = 0x10;
            c->unk2 = 0xE;
            c->unk7C = o;
        }
        o->unk7E = 0;
    }
    if (--o->unk7C == 0) {
        set_animation(o, 1);
        o->unk7C = 0;
        o->unk6++;
    }
}

void func_800F56AC_ovl09(Obj56AC* obj) {
    if (++obj->timer == 100) {
        obj->timer = 0;
        obj->state++;
        func_8002D9EC(obj, 0x40, 0x40);
    }
    if (obj->flag46 == 0) {
        set_animation(obj, 0);
    }
    animate_object(obj);
    apply_object_motion(obj);
    if (obj->timer >= 31 || (obj->timer & 1)) {
        func_8002D9EC(obj, 0x40, 0x40);
    }
}
