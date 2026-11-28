#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

extern s32 D_8009A0A8;

void func_800FA03C_ovl28(u8* obj) {
    s32 d = D_8009A0A8;

    func_8003D29C(0x14, (*(s32*)(obj + 8) >= d) << 6);
    obj[5] = 1;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 8);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x61] = 0x19;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    if (*(s32*)(obj + 0x24) > 0) {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s32*)(obj + 0x2C) = 0x4200;
    func_8002D9EC(obj, 0x30, 0x30);
}

extern u8* alloc_class3_slot(void);

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))

void func_800FA0DC_ovl28(u8* obj) {
    u8* child;
    s16 r;
    s32 v;

    animate_object(obj);
    apply_object_motion(obj);
    if (!(obj[0x70] & 8)) {
        return;
    }
    if (--S16(obj, 0x7C) == 0) {
        obj[5] = 2;
        child = alloc_class3_slot();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x1A;
            U16(child, 0xA) = U16(obj, 0xA);
            U16(child, 0xE) = U16(obj, 0xE);
            *(u8**)(obj + 0x80) = child;
        }
    }
    func_8002D9EC(obj, 0x30, 0x30);
    if (S16(obj, 0x7E)-- != 0) {
        return;
    }
    U16(obj, 0x42) ^= 0x8000;
    S8(obj, 0x61) -= 5;
    if (S8(obj, 0x61) >= 0x1A) {
        S8(obj, 0x61) = 0;
    }
    v = S8(obj, 0x61);
    if (v >= 6) {
        r = v;
    } else {
        r = 5;
    }
    S16(obj, 0x7E) = r;
}
#undef S16
#undef U16
#undef S8

void func_800FA1F0_ovl28(u8* a0) {
    u8* g;
    u8* p;

    animate_object(a0);
    func_8002D9EC(a0, 0x30, 0x30);
    g = g_playthrough_state.u;
    if (((s8*)g)[0x2A] == 1) {
        g[0x2A] = 2;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 7;
            *(u8**)(p + 0x7C) = a0;
        }
    }
    p = g_playthrough_state.u;
    if (((s8*)p)[0x2A] == 2) {
        p[0x2A] = 0;
        a0[5] = 3;
    }
}

extern u8 D_8009A0B5;

void func_800FA294_ovl28(u8* obj) {
    animate_object(obj);
    func_8002D9EC(obj, 0x48, 0x48);
    if (D_800D50DE == 0x1F) {
        func_8003D29C(0x48, D_8009A0B5);
        set_animation(obj, 9);
        obj[5] = 4;
    }
}

void func_800FA2FC_ovl28(u8* obj) {
    animate_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (((s8*)obj)[0x45] == 1 && D_800D50DE == 0) {
        if (((s8*)obj)[2] == 0) {
            func_8002385C(0x45, 0xFF, 0);
        } else {
            func_8002385C(0x47, 0xFF, 0);
        }
        obj[5] = 5;
    }
}

extern u8 D_80091C44;

void func_800FA38C_ovl28(u8* obj) {
    u8* p;
    u8* q;

    animate_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (D_80091C44 == 0) {
        p = g_playthrough_state.u;
        q = D_8009A1F8.u;
        p[0xF] = 0x10;
        p[0x24] = 0;
        *(s32*)(p + 0x20) = 0;
        *(u16*)(q + 0x2A) = *(u16*)(q + 0xE);
    }
}
