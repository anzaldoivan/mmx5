#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl03.h"

extern void func_80047184(s32 arg0);
extern u16 D_80093E68;
extern u8 D_8009A197;
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u16 D_800D50DE;

void func_800F7F98_ovl03(u8* obj) {
    if (*(u16*)(obj + 0x7C) & 1) {
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_800C9310 |= 1;
        D_80093E68 = 0x7C00;
    } else {
        D_800D50DE = 0;
        D_8009A42E = 0;
        D_80093E68 = 0;
        D_800C9310 |= 1;
    }
    if (++*(s16*)(obj + 0x7C) == 9) {
        set_animation(obj, 1);
        func_80047184(1);
        D_8009A197 = 1;
        *(u16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern u8 D_800F9E6C_ovl03[];
extern u8 D_8009A197;
extern u8 D_800D1C10;

void func_800F8084_ovl03(Obj8084* e) {
    s16 t;

    t = ++e->unk7C;
    if (t == 100) {
        e->unk54 = D_800F9E6C_ovl03;
        D_8009A197 = 0;
        D_800D1C10 = 0;
    } else if (t == 180) {
        u8 v;
        set_animation(e, 1);
        v = D_800FA0BC_ovl03[e->unk92][e->unk93++];
        e->unk6 = 0;
        e->unk5 = v;
    }
    animate_object(e);
    apply_object_motion(e);
}
