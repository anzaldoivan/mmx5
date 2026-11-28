#ifndef MMX5_OVL03_H
#define MMX5_OVL03_H

#include "types.h"

extern union {
    u8 u[8];
    s32 w[2];
} D_800F95AC_ovl03;

extern u8 D_800FA0BC_ovl03[][6];
extern union {
    u8 u;
    s8 s;
} D_800FA238_ovl03;

void func_800F161C_ovl03();
void func_800F89A8_ovl03();

#endif
