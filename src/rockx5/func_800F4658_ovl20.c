#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s8 D_800D1C00[];
extern u16 D_800F595C_ovl20[][2];

void func_800F4658_ovl20(u8* arg0) {
    if (*(s8*)(arg0 + 2) == 9) {
        *(u16*)(arg0 + 0xA) = D_800F595C_ovl20[D_800D1C00[0x2C] + 2][0];
        *(u16*)(arg0 + 0xE) =
            *(u16*)((u8*)D_800F595C_ovl20 + ((D_800D1C00[0x2C] + 2) << 2) + 2) +
            5;
    } else {
        *(u16*)(arg0 + 0xA) = D_800F595C_ovl20[D_800D1C00[0x2C]][0];
        *(u16*)(arg0 + 0xE) =
            *(u16*)((u8*)D_800F595C_ovl20 + (D_800D1C00[0x2C] << 2) + 2) + 5;
    }
    if ((u8)D_800D1C00[1] - 8 < 2U) {
        arg0[3] = 0;
        return;
    }
    func_8002D9EC(arg0, 0x80, 0x40);
}
