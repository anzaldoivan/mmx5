#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_800AA9A8[];
extern u8 D_800C9588[];
extern u8 D_80070980[];
extern u8 D_800708E0[];
extern u8 D_80070A20[];
extern u8 D_80070A80[];
extern u8 D_80070A60[];
extern u8 D_80070AC8[];
extern u8 D_80070AA0[];
extern u8 D_80070AC5;
extern u8 D_80070AB4[];

void func_80019BD4(void);
void func_80018AEC(u8, s32, s32, s32, s32, s32);
void func_80019130(void);
void func_80019C4C(void);

static inline s32 func_80018400_d2(void) {
    u8* p = g_Player;
    return ((s8*)p)[2];
}

static inline s32 func_80018400_d14(void) {
    u8* p = D_800D4F40.u;
    return ((s8*)p)[0x14];
}

static inline s32 func_80018400_c(s32 off) {
    u8* p = g_playthrough_state.u;
    return p[off];
}

static inline s32 func_80018400_b(u8* p) {
    return (s32)p;
}

void func_80018400(void) {
    s32 n;
    u8* a;
    u8* t;
    u8* b;
    u8* e;
    s32 i;
    s32 k;
    s32 m;
    s32 code;
    s32 c;
    u8* x;
    u8* y;
    u8* w;
    s32 j;
    s16* q;
    u8* o;
    u8* g;
    u8* ta;
    u8* tb;
    u8* tc;
    u8* td;

    n = D_1F800000;
    a = D_800AA9A8 + n * 0xA000;
    D_1F800100 = a;
    D_1F800104 = D_800C9588 + n * 0x2000;
    (&D_1F800100)[4] = a;
    func_80019BD4();
    func_80018AEC(0, 0x80, 0x80, 0x20, 0, 0);
    func_80018AEC(1, 0x120, 0x80, 0x20, 0, 0);
    func_80018AEC(2, 0x9C, 0x80, 0x21, 0, 0);
    if (func_80018400_d2() == 0) {
        func_80018AEC(0x33, 0x80, 0x80, 0x29, 0, 0);
    } else if (func_80018400_c(0x4A) & 0x10) {
        func_80018AEC(0x33, 0x80, 0x80, 0x34, 0, 0);
    } else {
        func_80018AEC(0x33, 0x80, 0x80, 0x24, 0, 0);
    }
    func_80018AEC(func_80018400_c(0xA0) + 0x38, 0x90, 0xEA, 0x21, 0, 0);
    func_80019130();

    if (func_80018400_d2() == 0) {
        t = D_800708E0;
    } else {
        t = D_80070980;
    }
    for (i = 0; i < 10; i++) {
        b = D_800D4F40.u;
        e = t + i * 8 + 0x50;
        if (((D4F40_80018400*)b)->f16[i] == 0) {
            continue;
        }
        if (func_80018400_d2() != 0 && i == 0 && b[0x16] != 1) {
            if (((s8*)b)[0x14] == 0 && (D_8009A420_as_s32 & 0x10)) {
                func_80018AEC(t[0x4C], *(u16*)(t + 0x48), *(u16*)(t + 0x4A),
                              t[0x4E] + 0x20, 0, 0);
                func_80018AEC(t[0x9C], *(u16*)(t + 0x98), *(u16*)(t + 0x9A),
                              t[0x9E], 0, -1);
            } else {
                func_80018AEC(t[0x4C], *(u16*)(t + 0x48), *(u16*)(t + 0x4A),
                              t[0x4D] + 0x20, 0, 0);
                func_80018AEC(t[0x9C], *(u16*)(t + 0x98), *(u16*)(t + 0x9A),
                              t[0x9D], 0, -1);
            }
        } else {
            if (((s8*)b)[0x14] == i && (D_8009A420_as_s32 & 0x10)) {
                func_80018AEC(e[-0x4C], *(u16*)(e - 0x50), *(u16*)(e - 0x4E),
                              e[-0x4A] + 0x20, 0, 0);
                func_80018AEC(e[4], *(u16*)(e + 0), *(u16*)(e + 2), e[6], 0,
                              -1);
            } else {
                func_80018AEC(e[-0x4C], *(u16*)(e - 0x50), *(u16*)(e - 0x4E),
                              e[-0x4B] + 0x20, 0, 0);
                func_80018AEC(e[4], *(u16*)(e + 0), *(u16*)(e + 2), e[5], 0,
                              -1);
            }
        }
    }

    k = func_80018400_d14();
    if (k < 10) {
        if (func_80018400_d2() == 0) {
            func_80018AEC(
                0x22,
                *(u16*)(((k + 10) << 3) + func_80018400_b(D_800708E0)) - 8,
                *(u16*)(D_800708E0 + ((k + 10) << 3) + 2) - 8, 0x22, 0, 0);
        } else {
            func_80018AEC(
                0x22,
                *(u16*)(((k + 10) << 3) + func_80018400_b(D_80070980)) - 8,
                *(u16*)(D_80070980 + ((k + 10) << 3) + 2) - 8, 0x22, 0, 0);
        }
    }

    g = D_80070A20;
    for (i = 10; i < 18; i++) {
        o = D_800D4F40.u;
        e = g + i * 8 - 0x50;
        if (((D4F40_80018400*)o)->f16[i] != 0) {
            if (((s8*)o)[0x14] == i && (D_8009A420_as_s32 & 0x10)) {
                func_80018AEC(e[4], *(u16*)(e + 0), *(u16*)(e + 2), e[6] + 0x20,
                              0, 0);
            } else {
                func_80018AEC(e[4], *(u16*)(e + 0), *(u16*)(e + 2), e[5] + 0x20,
                              0, 0);
            }
        }
    }

    ta = D_80070A80;
    tb = ta + 1;
    tc = D_80070A60;
    td = tc + 1;
    q = (s16*)D_80070AC8;
    for (i = 0; i < 4; i++) {
        c = D_800D4F40.u[i + 0x28];
        if (c != 0) {
            if (func_80018400_d2() != 0) {
                j = c - 1;
                func_80018AEC(ta[j * 2], q[0], q[1], tb[j * 2] + 0x20, 0, 0);
            } else {
                j = c - 1;
                func_80018AEC(tc[j * 2], q[0], q[1], td[j * 2] + 0x20, 0, 0);
            }
        }
        q += 2;
    }

    w = g_playthrough_state.u;
    func_80018AEC(w[0x45] + 6, 0x8A, 0x18, 0x23, 0, 0);
    y = D_800D4F40.u;
    func_80018AEC(y[0x2C] + 0x10, 0x50, 0x11, 0x23, 0, 0);
    x = g_Player;
    if (((s8*)x)[2] == 0) {
        if (((s8*)y)[0x14] == 9) {
            if (x[0xFA] == 2) {
                code = 0x12;
            } else if (x[0xFA] == 3) {
                code = 0x13;
            } else {
                code = 0x11;
            }
            func_80018AEC(code, 0xE0, 0xCE, 0, 2, 1);
        } else {
            func_80018AEC(D_80070AA0[((s8*)y)[0x14]], 0xE0, 0xCE, 0, 2, 1);
        }
    } else if (((s8*)y)[0x14] == 0 && w[0x1BA] == 0) {
        func_80018AEC(D_80070AC5, 0xE0, 0xCE, 0, 2, 1);
    } else {
        func_80018AEC(D_80070AB4[func_80018400_d14()], 0xE0, 0xCE, 0, 2, 1);
    }
    func_80019C4C();
}
