#ifndef MMX5_OVL33_H
#define MMX5_OVL33_H

#include "types.h"

extern s16 D_800FF054_ovl33;
extern s16 D_800FF056_ovl33;
extern union {
    u8 u[4];
    s32 w[1];
} D_800FEADC_ovl33;
extern union {
    u8 u[4];
    s32 w[1];
} D_800FEAE0_ovl33;

void func_800FB744_ovl33();
void func_800FD4BC_ovl33();

#endif
