#include "types.h"
#include "mmx5/globals.h"

#define D_800F5024_ovl24 D_800F52B4_ovl20

#define func_800EFFBC_ovl24 func_800F185C_ovl20
#include "shared/func_800EFFBC_ovl24.c"
#undef func_800EFFBC_ovl24
#undef D_800F5024_ovl24

extern u8 D_800D1C27;

void func_800F1898_ovl20(u8* arg0) {
    func_8002385C(0, 0xFF, 0);
    arg0[3] = 0;
    arg0[2]++;
    D_800D1C27 = 0x20;
}

#include "shared/func_800F18E4_ovl20.c"

extern u8 D_800F5FE0_ovl20[];
extern u8 D_800F5FE9_ovl20;

void func_800F1914_ovl20(u8* arg0) {
    s32 i;
    u8 v;

    if (D_800D1C28[1] == 0) {
        *(s16*)(arg0 + 8) = 0;
        *(s16*)(arg0 + 0xA) = 0;
        for (i = 0; i < 9; i++) {
            if (i < 4) {
                D_800F5FE0_ovl20[i] = 1;
            } else {
                D_800F5FE0_ovl20[i] = 0;
            }
        }
        if (arg0[0x79] < 5 && (v = arg0[0x10F]) != 2 && v != 4) {
            D_800F5FE9_ovl20 = 8;
        } else {
            D_800F5FE9_ovl20 = 9;
        }
        arg0[1] = 3;
        arg0[2] = 2;
        arg0[0x79] = 2;
    }
}
