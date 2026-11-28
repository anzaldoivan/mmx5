#include "types.h"
#include "mmx5/system.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C41C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 g_angle_x_speeds[];
extern s32 g_angle_y_speeds[];

void func_80051F48(void* arg0) {
    s32 sy;
    s32 sx;
    s32 i;
    s32 vx;
    s32 vy;

    M2C_FIELD(arg0, u8*, 0x36) = 0;
    M2C_FIELD(arg0, s16*, 0x34) = 1;
    M2C_FIELD(arg0, u8*, 0x37) = 0;
    M2C_FIELD(arg0, u8*, 0) |= 0x82;
    M2C_FIELD(arg0, u8*, 0x38) = random_byte() & 0x1F;
    if (M2C_FIELD(arg0, u8*, 0x38) < 0x10) {
        sy = -1;
        if (M2C_FIELD(arg0, u8*, 0x38) < 8) {
            sx = 1;
            i = 8 - M2C_FIELD(arg0, u8*, 0x38);
        } else {
            sx = -1;
            i = M2C_FIELD(arg0, u8*, 0x38) - 8;
        }
    } else {
        sy = 1;
        if (M2C_FIELD(arg0, u8*, 0x38) < 0x18) {
            sx = -1;
            i = 0x18 - M2C_FIELD(arg0, u8*, 0x38);
        } else {
            sx = 1;
            i = M2C_FIELD(arg0, u8*, 0x38) - 0x18;
        }
    }
    vx = (g_angle_x_speeds[i] * sx << 4) >> 4;
    M2C_FIELD(arg0, s32*, 0x3C) = vx;
    vy = g_angle_y_speeds[i] * sy << 4;
    M2C_FIELD(arg0, s32*, 0x44) = vx;
    M2C_FIELD(arg0, s32*, 0x4C) = vx;
    M2C_FIELD(arg0, s32*, 0x54) = vx / 2;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x30) = 0;
    M2C_FIELD(arg0, u8*, 0x39) = 4;
    M2C_FIELD(arg0, u8*, 0x3A) = 0;
    M2C_FIELD(arg0, u8*, 4) += 1;
    M2C_FIELD(arg0, s32*, 0x40) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x48) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x50) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x58) = (vy >> 4) / 2;
}
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C584.c, AGPL-3.0 (THIRD_PARTY.md). */

void func_80032CEC();

#define W(o) (*(s32*)((u8*)arg0 + (o)))
#define B(o) (*(u8*)((u8*)arg0 + (o)))
#define SB(o) (*(s8*)((u8*)arg0 + (o)))

void func_800520B0(void* arg0) {
    if (++B(0x3A) == 0) {
        B(0x3A) = 0xFE;
    }
    W(0x14) += W(0x3C);
    W(0x18) += W(0x40);
    W(0x24) += W(0x44);
    W(0x28) += W(0x48);
    W(0x1C) = W(0x14) + 0x10000;
    W(0x20) = W(0x18) + 0x10000;
    W(0x2C) = W(0x24) - 0x10000;
    W(0x30) = W(0x28) - 0x10000;
    W(0x3C) += W(0x4C);
    W(0x40) += W(0x50);
    W(0x44) += W(0x54);
    W(0x48) += W(0x58);
    if (B(0x39) != 0) {
        B(0x39)--;
        return;
    }
    func_80032CEC(arg0);
    if (SB(0x3) == 0 && B(0x3A) >= 0x3D) {
        B(0x4)++;
    }
}

#undef W
#undef B
#undef SB
