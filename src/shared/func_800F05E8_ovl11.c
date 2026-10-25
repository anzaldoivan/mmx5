/* Shared body (DK-5), from the banked draft of func_800F05E8_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EB56C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);

extern M2C_UNK D_80075160;
extern X4_Obj D_8009A0A0;
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

void DEDUP_NAME(void* self) {
    X4_Obj* p = &D_8009A0A0;
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
    func_800171E8(self, 0);
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
