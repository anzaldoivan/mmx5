/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029B8C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16** D_80072D10[];
#define M2C_UNK s32
extern M2C_UNK D_8009A0A0;
#define D_8009A0A0 (*(X4_Obj*)&D_8009A0A0)
extern X4_BackgroundObj D_8009A1F8[3];
extern X4_EngineObj D_800D1C00;

void func_8002ACC4(void) {
    X4_BackgroundObj* bg;
    s16* src;
    // !FAKE: X4_EngineObj lacks stage (0x0C), substage (0x0D), checkpoint (0x1D): pinned offsets
    // via byte pointer; tbl local orders the D_80072D10 lui first (byte mismatch without both)
    s16*** tbl = D_80072D10;
    s8* eng = (s8*)&D_800D1C00;

    src = tbl[eng[0xC] * 2 + eng[0xD]][eng[0x1D]];
    {
        // !FAKE: pins v0 to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 v0 asm("$3");
        s32 v1;
        v0 = src[0] << 16;
        D_8009A0A0.x_pos.val = v0;
        v1 = src[1] << 16;
        D_8009A0A0.unk18.val = v0;
        D_8009A0A0.y_pos.val = v1;
        D_8009A0A0.unk1C.val = v1;
    }
    D_8009A0A0.unk15 = ((u8*)src)[0x18];
    bg = D_8009A1F8;
    bg->x_pos.i.hi = src[2];
    bg->unk14.i.hi = src[2];
    bg->y_pos.i.hi = src[3];
    bg->unk18.i.hi = src[3];
    M2C_FIELD(bg, s16*, 0x1E) = src[8];
    M2C_FIELD(bg, s16*, 0x26) = src[8];
    M2C_FIELD(bg, s16*, 0x1C) = src[9];
    M2C_FIELD(bg, s16*, 0x24) = src[9];
    M2C_FIELD(bg, s16*, 0x22) = src[10];
    M2C_FIELD(bg, s16*, 0x2A) = src[10];
    M2C_FIELD(bg, s16*, 0x20) = src[11];
    M2C_FIELD(bg, s16*, 0x28) = src[11];
    bg++;
    {
        s32 a;
        s32 b;
        bg->unk40 = a = (u16)src[13];
        bg->unk42 = b = (u16)src[14];
        bg->unk14.i.hi = bg->x_pos.i.hi = a + src[4];
        bg->unk18.i.hi = bg->y_pos.i.hi = b + src[5];
    }
    bg++;
    {
        s32 a;
        // !FAKE: pins b to $7; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 b asm("$7");
        bg->unk40 = a = (u16)src[15];
        bg->unk42 = b = (u16)src[16];
        bg->unk14.i.hi = bg->x_pos.i.hi = a + src[6];
        bg->unk18.i.hi = bg->y_pos.i.hi = src[7] + b;
    }
    ((u8*)&D_8009A0A0)[0xCE] = ((u8*)src)[0x22];
}
#undef D_8009A0A0
