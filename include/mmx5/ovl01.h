#ifndef MMX5_OVL01_H
#define MMX5_OVL01_H

#include "types.h"

extern union {
    u8 u[0x1B0];
    u16 r[0x36][4];
} D_800FCFF0_ovl01;
extern u8 D_800FD9CC_ovl01[];
extern union {
    u8 u[0x3C];
    u16 h[0x1E];
} D_800FDA5C_ovl01;

extern s16
    D_800FD408_ovl01[][3]; /* 6-byte rows: [1], [2] passed to is_off_screen */

void func_800F074C_ovl01();
void func_800F4908_ovl01();
void func_800F6BDC_ovl01();
void func_800FB308_ovl01();

#endif
