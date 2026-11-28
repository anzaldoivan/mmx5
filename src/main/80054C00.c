#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_8003240C(u8* a0);
extern void func_80054F90(u8* a0);
extern s32 func_800549E8(u8* a0);
extern void func_8002CF70(void);
extern s8 D_800D1C1C;
extern s8 D_800D1C1D;
extern s8 D_800D1C26;

void func_80054C00(u8* a0, s32 a1, u8* a2) {
    s8 t;
    u8* p;

    func_8003240C(a0);
    func_80054F90(a0);
    t = ((s8*)a0)[2];
    if (t == 2 && !(D_800D1C26 & 8)) {
        return;
    }
    if (t == 4 && !(D_800D1C26 & 8)) {
        return;
    }
    if (func_800549E8(a0) == 0) {
        return;
    }
    if (*(s32*)(a0 + 0x7C) == 0) {
        func_8002CF70();
        D_800D1C1C = 1;
    }
    if (((s8*)a0)[2] == 1) {
        D_800D1C26 = 1;
    }
    a2[0xD4] = 1;
    if (((s8*)a0)[2] == 7) {
        D_800D1C26 = 1;
    }
    if (((s8*)a0)[2] == 6) {
        u8* q = D_8009A1F8.u;
        D_800D1C1D = 2;
        *(s16*)(q + 0x2A) = 0x4B0;
    }
    p = D_8009A1F8.u;
    *(u16*)(p + 0x34) &= 0xF;
    a0[5] = 1;
}

void func_80054D24(u8* a0, u8* a1, u8* a2) {
    u8* p;

    if (*(s8*)(a2 + 0xD4) < 0) {
        a1[0x10] = 1;
        a1[0x12] = 1;
        play_sound(0, 0x10, a0);
        p = D_8009A1F8.u;
        *(s32*)(a2 + 0x68) = 0;
        a0[5] = 2;
        *(s32*)(a0 + 0x80) = *(s8*)(p + 0x47);
        p[0x47] = 2;
    }
}

#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

extern void func_8003CD08(u8* obj);
extern s32 D_800E92F8;

void func_80054D9C(u8* obj, s32 arg1, u8* other) {
    s8 t;
    u8* p;

    *(s32*)(other + 8) += *(s32*)(obj + 0x84);
    if (*(s8*)(obj + 2) == 1) {
        u8* q = D_8009A1F8.u;
        *(u16*)(q + 0x94) -= 4;
    }
    p = D_8009A1F8.u;
    if (*(s16*)(p + 0xA) == *(s16*)(p + 0x26)) {
        other[0xD4] = 0;
        func_8003CD08(other);
        obj[5] = 4;
        set_animation(obj, 1);
        play_sound(0, 0x11, obj);
        t = *(s8*)(obj + 2);
        if (t == 6 || t == 10) {
            D_800E92F8 = 1;
        } else if (t == 9) {
            D_800D1C28_as_u8 = 1;
        }
        {
            u8* r = D_8009A1F8.u;
            r[0x47] = obj[0x80];
        }
    }
}
#undef D_800D1C28_as_u8

extern s16 D_8009A220[];
extern s8 D_800D1C1C;
extern s8 D_800D1C1D;
extern s8 D_800D1C27;
extern s32 D_800E92F8;

void func_80054E84(u8* obj) {
    s8 kind;
    u8* p;

    if (((s8*)obj)[0x45] < 2) {
        animate_object(obj);
        if (((s8*)obj)[0x45] == 1) {
            play_sound(0, 0x10, obj);
            obj[0x45] = 0;
        }
    } else {
        kind = ((s8*)obj)[2];
        obj[4] = 2;
        obj[5] = 0;
        if (kind == 1) {
            D_800D1C1D = 3;
        } else if (kind == 3) {
            D_800E92F8 = 1;
            D_8009A220[0] = 0;
        } else if (kind == 8) {
            D_800D1C27 = 1;
        }
        p = g_Player;
        if (((s8*)p)[0xD0] == 0 && ((s8*)p)[0xD4] == 0) {
            D_800D1C1C = 0;
        }
    }
}
