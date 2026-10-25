/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80052300.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D760();
extern u8* D_8007D54C[];
extern s32 D_8007D554[][16];
extern s32 D_80093DD0[];
extern s8 D_80093E66;
extern s16 D_80093E68;
extern s8 D_8009A42C;
extern s16 D_8009A42E;
extern X4_Obj D_8009E7A0[0x20];
extern s8 D_800D50DC;
extern s16 D_800D50DE;

void func_80056144(void* arg0) {
    u8 i;
    u16 c;
    u8* p;

    i = 0;
    if (M2C_FIELD(arg0, s8*, 2) != -1) {
        M2C_FIELD(arg0, u8**, 0x14) = D_8007D54C[M2C_FIELD(arg0, s8*, 2)];
        M2C_FIELD(arg0, u8*, 0x18) = M2C_FIELD(arg0, u8**, 0x14)[2];
        do {
            D_80093DD0[i] = D_8007D554[M2C_FIELD(arg0, s8*, 2)][i];
            i++;
        } while (i < 0x10);
        D_800D50DC = M2C_FIELD(arg0, u8**, 0x14)[3] & 1;
        D_8009A42C = M2C_FIELD(arg0, u8**, 0x14)[3] & 2;
        D_80093E66 = M2C_FIELD(arg0, u8**, 0x14)[3] & 4;
        c = *(u16*)M2C_FIELD(arg0, u8**, 0x14);
        D_800D50DE = c & 0x1F;
        D_8009A42E = c & 0x3E0;
        D_80093E68 = c & 0x7C00;
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    D_80093E68 = 0;
    D_8009A42E = 0;
    D_800D50DE = 0;
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    for (p = (u8*)D_8009E7A0; p < (u8*)D_8009E7A0 + 0x1200; p += 0x30) {
        if (M2C_FIELD(p, s8*, 2) == 2 && p != arg0) {
            func_8002D760(p);
        }
    }
    func_8002D760(arg0);
}
