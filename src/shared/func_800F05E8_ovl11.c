#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EB56C.c, AGPL-3.0 (THIRD_PARTY.md). */
#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80075160;
extern M2C_UNK D_800F9760_ovl11;
extern M2C_UNK D_800F9764_ovl11;
extern M2C_UNK D_800F9768_ovl11;
extern M2C_UNK D_800F9854_ovl11;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

void func_800F05E8_ovl11(void* self) {
    X4_Obj* p = &g_Player_as_X4_Obj;
    s32 x;
    s32 t;

    U8(0x0) = 0x41;
    U8(0x5C) = 0x1E;
    U8(0x61) = 0;
    U8(0x60) = 4;
    t = M2C_FIELD(p, u8*, 0x14);
    {
        // !FAKE: pins a to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
        register void* a asm("$2") = &D_80075160;
        PTR(0x58) = a;
    }
    PTR(0x30) = &D_800F9854_ovl11;
    U8(0x16) = 5;
    x = S32(0x8);
    PTR(0x68) = &D_800F9768_ovl11;
    PTR(0x54) = &D_800F9760_ovl11;
    PTR(0x50) = &D_800F9764_ovl11;
    S32(0x20) = 0;
    S32(0x24) = 0;
    S32(0x28) = 0;
    S32(0x2C) = 0;
    U8(0x67) = 0;
    U8(0x14) = t;
    S32(0x18) = x;
    S32(0x1C) = S32(0xC);
    switch (U8(0x2) >> 4) {
    case 0:
        U8(0x15) = (p->x_pos.val >= x) << 6;
        break;
    case 1:
        U8(0x15) = 0;
        break;
    case 2:
        U8(0x15) = 0x40;
        break;
    }
    set_animation(self, 0);
    {
        // !FAKE: pins v to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 v asm("$2") = 2;
        U8(0x5) = v;
        v = U8(0x4);
        U16(0x7C) = 0x28;
        S32(0x80) = 0;
        S32(0x84) = 0;
        S32(0x88) = 0;
        S32(0x8C) = 0;
        S32(0x90) = 0;
        S32(0x94) = 0;
        U8(0x6) = 0;
        U8(0x4) = v + 1;
    }
    if (S8(0x2) == 2) {
        U16(0x7C) = 0xA;
    }
}

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800F0F28_ovl11(u8* a0);
extern u8 D_8009A197;
extern u8 D_800F988C_ovl11[];
extern void* D_800F98A8_ovl11[];

void func_800F075C_ovl11(u8* a0) {
    s32 r;
    u8 f;

    if (D_8009A197 == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        ((void (*)(u8*))D_800F98A8_ovl11[(s8)a0[5]])(a0);
        func_800F0F28_ovl11(a0);
    }
    r = func_80031DD0(a0);
    func_800317B8(a0);
    if (r < 0 || ((f = a0[0x70]) & 0xC) == 0xC || (f & 3) == 3) {
        func_8004D4F4(5, D_800F988C_ovl11, a0);
        a0[3] = 0;
        *(s16*)(a0 + 0x7C) = 0x1E;
        *(s16*)(a0 + 0x7E) = 5;
        a0[4]++;
        return;
    }
    if (is_off_screen(a0, 0x60, 0x40) == 0) {
        func_8002D9EC(a0, 0x30, 0x30);
        return;
    }
    a0[4] = 4;
}
