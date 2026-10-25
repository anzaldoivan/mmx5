/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053D18.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define NULL ((void*)0)

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* func_8002D53C(void); /* extern */
s32 func_8002DF78();                    /* extern */
extern u16 D_80093F70;

void func_800578DC(void* arg0) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    func_8002DF78();
    M2C_FIELD(arg0, u16*, 0x1C) = (u16)(D_80093F70 & 0xFFF);
    temp_v0 = ((void* (*)())func_8002D53C)();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8*, 0) = 1;
        M2C_FIELD(temp_v0, s8*, 1) = 4;
        M2C_FIELD(temp_v0, u16*, 8) = (u16)M2C_FIELD(arg0, u16*, 0x1C);
        M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_2 = ((void* (*)())func_8002D53C)(temp_v0);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s8*, 0) = 1;
        M2C_FIELD(temp_v0_2, s8*, 1) = 4;
        M2C_FIELD(temp_v0_2, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0x555) & 0xFFF);
        M2C_FIELD(temp_v0_2, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_2, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_3 = ((void* (*)())func_8002D53C)(temp_v0_2);
    if (temp_v0_3 != NULL) {
        M2C_FIELD(temp_v0_3, s8*, 0) = 1;
        M2C_FIELD(temp_v0_3, s8*, 1) = 4;
        M2C_FIELD(temp_v0_3, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0xAAA) & 0xFFF);
        M2C_FIELD(temp_v0_3, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_3, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    M2C_FIELD(arg0, s16*, 0x14) = 8;
    M2C_FIELD(arg0, s8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
