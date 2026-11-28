#include "types.h"

extern u8 D_80077514[];
extern u8 D_80077518[];
extern u8 D_8007751C[];

void func_8004CED0(u8* a0) {
    u8* a2;
    u16 e;

    a0[4] = 1;
    a2 = *(u8**)(a0 + 0x7C);
    a0[3] = 0;
    a0[0x16] = 0;
    *(s32*)(a0 + 0x68) = 0;
    *(s32*)(a0 + 0x54) = 0;
    *(u8**)(a0 + 0x50) = D_80077514;
    switch (((s8*)a0)[2]) {
    case 0:
        *(u8**)(a0 + 0x50) = D_80077514;
        break;
    case 1:
        *(u8**)(a0 + 0x50) = D_80077518;
        break;
    case 2:
        *(u8**)(a0 + 0x50) = D_8007751C;
        break;
    }
    *(s16*)(a0 + 0xA) = *(s16*)(a2 + 0xA);
    e = *(u16*)(a2 + 0xE);
    a0[0x5C] = 0;
    a0[0x60] = 0;
    *(s16*)(a0 + 0xE) = e;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800466C4.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004CF64(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a1, s8*, 4) == 1) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            goto block_3; // !FAKE: control flow kept from the mmx6 twin
        }
    } else {
    block_3:
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
