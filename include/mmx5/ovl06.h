#ifndef MMX5_OVL06_H
#define MMX5_OVL06_H

#include "types.h"

extern union {
    u8 u[4];
    s32 w[1];
} D_800FF1DC_ovl06;
extern union {
    u8 u[4];
    s32 w[1];
} D_800FF1E0_ovl06;

extern Ent800F43E8 D_800FF7FC_ovl06[];
extern s16 D_800FF94C_ovl06;
extern s16 D_800FF94E_ovl06;

void func_800F9180_ovl06();
void func_800FAEF8_ovl06();
void func_800FD5E4_ovl06();

#endif
