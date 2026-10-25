/* Adapted from mmx6 @c1c892d src/shared/rock_12/func_800E9A98.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define F(p, T, o) (*(T*)((u8*)(p) + (o)))

struct X4_QuadObj* func_8002D53C(void);
extern u16 D_800F1F04_ovl16[][8];
extern u16 D_800F1F34_ovl16[];

void func_800EEBA8_ovl16(void* arg0) {
    struct X4_QuadObj* child;
    s32 idx;

    F(arg0, s8, 0x37) = -1;
    F(arg0, u8, 0x3) = 1;
    F(arg0, s32, 0x8) = 0;
    F(arg0, s32, 0xC) = 0;
    F(arg0, u8, 0x4)++;
    if (F(arg0, s8, 0x2) == 0) {
        child = func_8002D53C();
        F(arg0, void*, 0x38) = child;
        if (child != 0) {
            F(child, u8, 0x0) = 1;
            F(F(arg0, void*, 0x38), u8, 0x1) = 0xA;
            F(F(arg0, void*, 0x38), u8, 0x36) = F(arg0, u8, 0x36);
            F(F(arg0, void*, 0x38), u8, 0x2) = 1;
        }
    }
    idx = F(arg0, s8, 0x2);
    F(arg0, u16, 0x16) = D_800F1F04_ovl16[idx][0];
    F(arg0, u16, 0x1A) = D_800F1F04_ovl16[idx][1];
    F(arg0, u16, 0x1E) = D_800F1F04_ovl16[idx][2];
    F(arg0, u16, 0x22) = D_800F1F04_ovl16[idx][3];
    F(arg0, u16, 0x26) = D_800F1F04_ovl16[idx][4];
    F(arg0, u16, 0x2A) = D_800F1F04_ovl16[idx][5];
    F(arg0, u16, 0x2E) = D_800F1F04_ovl16[idx][6];
    F(arg0, u16, 0x32) = D_800F1F04_ovl16[idx][7];
    F(arg0, u16, 0x34) = D_800F1F34_ovl16[idx];
}
