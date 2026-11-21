#include "types.h"
#include "mmx5/globals.h"

#define D_800F5024_ovl24 D_800F5064_ovl24

#define func_800EFFBC_ovl24 func_800F037C_ovl24
#include "shared/func_800EFFBC_ovl24.c"
#undef func_800EFFBC_ovl24
#undef D_800F5024_ovl24

extern s8 D_800F5F7B_ovl24;
extern s8 D_800F5F7C_ovl24;
extern s8 D_800F5F7D_ovl24;
extern s8 D_800F5F7E_ovl24;

s32 func_800EFC48_ovl24(u8* a0);

void func_800F03B8_ovl24(u8* a0) {
    D_800F5F7B_ovl24 = 0;
    D_800F5F7C_ovl24 = 0;
    D_800F5F7D_ovl24 = 0;
    D_800F5F7E_ovl24 = func_800EFC48_ovl24(a0);
    a0[2]++;
}

#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

extern s8 D_800F5F7D_ovl24;
extern u16 D_800C9320;
extern s8 D_800F5F7B_ovl24;
extern s8 D_800F5F7E_ovl24;

void func_800F0410_ovl24(u8* arg0) {
    if (D_800F5F7D_ovl24 != 0) {
        if (!(D_800C9320 & 0x8FF)) {
            return;
        }
        if (D_800F5F7B_ovl24 < 0x20 || D_800F5F7E_ovl24 != 0) {
            D_800D1C28_as_u8 = 0x40;
            D_800F5F7D_ovl24 = 0;
            arg0[2] = 1;
            return;
        }
    }
    D_800D1C28_as_u8 = 0x7F;
    arg0[2]++;
}
#undef D_800D1C28_as_u8

#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

extern void func_800EF9D0_ovl24(void);
extern s8 D_800F5F7A_ovl24;

void func_800F04A0_ovl24(u8* arg0) {
    if (D_800F5F7A_ovl24 != 0) {
        func_800EF9D0_ovl24();
    }
    D_800D1C28_as_u8 = 0x7F;
    arg0[1] = 4;
    arg0[2] = 0;
}
