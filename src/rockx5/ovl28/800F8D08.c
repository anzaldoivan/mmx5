#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;
extern u8 D_8009A23F;

void func_800F8D08_ovl28(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        D_8009A23F = 2;
        ((s32(*)())func_8003D29C)(0x1D, 0x40);
        a->unk7C = 0x28;
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(s16*)(p + 0xA) = a->unkA;
            *(s16*)(p + 0xE) = a->unkE;
            *(u8**)((u8*)a + 0x80) = p;
        }
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 8;
            *(Obj3DD4**)(p + 0x7C) = a;
        }
        a->unk6++;
    }
}

extern u8 D_800FE378_ovl28[];

void func_800F8DCC_ovl28(u8* obj) {
    if (*(s16*)(obj + 0xE) >= 0x2A0) {
        *(u8**)(obj + 0x68) = D_800FE378_ovl28;
    }
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s8*)(obj + 0x46) == 0) {
        u8* p = g_playthrough_state.u;
        func_8002385C(0x44, 0xFF, ((s8*)p)[0x2E]);
        p[0x2E] = 1;
        set_animation(obj, 2);
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    animate_object(obj);
    move_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}

#define func_800EFC34_ovl12 func_800F8E94_ovl28
#include "shared/func_800EFC34_ovl12.c"
#undef func_800EFC34_ovl12

extern s32 func_80044DE0();

void func_800F8EF0_ovl28(Ent8EF0* obj) {
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.t.unk26 = obj->unk94;
    D_8009A1F8.t.unk2A = D_8009A1F8.t.unk28;
    if (obj->unk5C < D_800D1CA2) {
        if (--obj->unk7C == 0) {
            play_sound(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.t.unk48 = 8;
    func_8003D2C4();
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    obj->unk5 = 3;
    obj->unk6 = 0;
}

extern u8 D_800FE378_ovl28[];

void func_800F8FF0_ovl28(u8* obj) {
    if (*(s16*)(obj + 0xE) >= 0x2A0) {
        *(u8**)(obj + 0x68) = D_800FE378_ovl28;
    }
    if (*(s16*)(obj + 0xE) >= 0x2E0) {
        s8* g = g_playthrough_state.s;
        s32 v = g[0x2E];
        if (v == 1) {
            obj[6] += 2;
        } else {
            func_8002385C(0x46, 0xFF, v);
            g[0x2E] = 1;
            *(s32*)(obj + 0x2C) = -0x2000;
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 1;
        }
    }
    animate_object(obj);
    move_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}

extern u8 D_80091C44;

void func_800F90BC_ovl28(u8* obj) {
    if (D_80091C44 == 0) {
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
    if (++*(s16*)(obj + 0x7C) == 0x20) {
        *(s16*)(obj + 0x7C) = 0;
        *(s32*)(obj + 0x2C) = -*(s32*)(obj + 0x2C);
    }
    *(s32*)(obj + 0xC) += *(s32*)(obj + 0x2C);
    animate_object(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}

extern void silence_sound(s32, s32);
extern void func_80044DD0(s32 a0);

void func_800F9150_ovl28(u8* obj) {
    if (obj[0x70] & 8) {
        silence_sound(2, 0x90);
        func_80044DD0(0);
        set_animation(obj, 2);
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    animate_object(obj);
    move_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}

extern s32 func_80044DE0();

void func_800F91D8_ovl28(Ent8EF0* obj) {
    u8* g = g_playthrough_state.u;

    g[0x24] = 1;
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.t.unk26 = obj->unk94;
    D_8009A1F8.t.unk2A = D_8009A1F8.t.unk28;
    if (obj->unk5C < ((s8*)g)[0xA2]) {
        if (--obj->unk7C == 0) {
            play_sound(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.t.unk48 = 8;
    func_8003D2C4();
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    obj->unk5 = 3;
    obj->unk6 = 0;
}
