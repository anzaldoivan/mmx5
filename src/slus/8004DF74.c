#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80048268.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8004E2BC(void*, u8);
extern u8 D_8007B50C[];

void func_8004DF74(void* arg0) {
    register s32 t asm("$2"); // !FAKE: depin breaks match (55/70)

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), u8*, 0x16) != 0) {
        func_8004E2BC(arg0, 0);
        {
            s8 c = M2C_FIELD(arg0, s8*, 2);
            t = 1;
            M2C_FIELD(arg0, u8*, 5) = t;
            t = 8;
            M2C_FIELD(arg0, u16*, 0x54) = t;
            if (c != 0) {
                M2C_FIELD(arg0, s16*, 0x42) = 0x7840;
                M2C_FIELD(arg0, s32*, 0x20) = 0x4000;
                M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
                return;
            }
        }
        M2C_FIELD(arg0, s32*, 0x20) = -0x4000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
        play_sound(0, 0xA, 0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0 && M2C_FIELD(arg0, u16*, 0x5C) == 0) {
        t = M2C_FIELD(arg0, u16*, 0x54);
        if (t != 0) {
            M2C_FIELD(arg0, u16*, 0x54) = t - 1;
            return;
        }
        func_8004E2BC(arg0, D_8007B50C[M2C_FIELD(arg0, u16*, 0x58)]);
        {
            t = M2C_FIELD(arg0, u16*, 0x58);
            M2C_FIELD(arg0, u16*, 0x58) = ++t;
            if ((u16)t >= 0xE) {
                M2C_FIELD(arg0, u16*, 0x58) = 0;
                M2C_FIELD(arg0, u16*, 0x5C) = 1;
            }
        }
    }
}
#undef M2C_UNK
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80048380.c, AGPL-3.0 (THIRD_PARTY.md). */

extern s8 D_800D1C1E;
extern u16 D_800E9568[];

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8004E08C(void* arg0) {
    s32 a;
    register s32 b asm("$3"); // !FAKE: depin breaks match (64/70)

    if (F16(arg0, 0x56) != 0) {
        F16(arg0, 0x56)--;
        return;
    }
    if (--F16(arg0, 0x54) == 0) {
        if (F8(arg0, 6) == 0) {
            if (F8(arg0, 2) != 0) {
                a = -0x4000;
                b = 0x8000;
            } else {
                a = 0x4000;
                b = -0x8000;
            }
            do {
                F32(arg0, 0x20) = a;
                F32(arg0, 0x24) = b;
            } while (0);
            F8(arg0, 6) = 1;
            F16(arg0, 0x54) = 8;
            F16(arg0, 0x56) = 0x1E;
            return;
        }
        F8(arg0, 5) = 2;
        F8(arg0, 6) = 0;
        F16(arg0, 0x42) = 0x7801;
        if (F8(arg0, 2) != 0) {
            F32(arg0, 0x20) = 0xFFF00000;
            func_8002C338(0x10, (s32*)D_800E9568, 1);
        } else {
            F32(arg0, 0x20) = 0x100000;
        }
        F32(arg0, 0x24) = 0;
        F16(arg0, 0xA) = 0xA0;
        F16(arg0, 0xE) = 0x78;
        D_800D1C1E = 1;
        return;
    }
    apply_object_motion(arg0);
}
#undef F8
#undef F16
#undef F32

extern u8 D_800D1C00[];

void func_8004E1A4(u8* obj) {
    u8* p;

    if (((s8*)obj)[3] != 0) {
        apply_object_motion(obj);
    } else {
        obj[4] = 2;
        obj[5] = 0;
        p = D_800D1C00;
        if (((s8*)p)[0xC] == 5 && ((s8*)p)[0x1D] == 0) {
            p[0x1C] = 0;
        }
    }
}
