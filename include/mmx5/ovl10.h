#ifndef MMX5_OVL10_H
#define MMX5_OVL10_H

#include "types.h"

extern union {
    u8 u[0x20];
    u8 r[6][5];
} D_800FBE00_ovl10;
extern union {
    u8 b;
    u8 u[4];
} D_800FC1C8_ovl10;

s32 func_800F912C_ovl10();

#endif
