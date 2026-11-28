#ifndef MMX5_OVL20_H
#define MMX5_OVL20_H

#include "types.h"

extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800F5FF0_ovl20;
extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800F63F0_ovl20;
extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800F67F0_ovl20;

extern union {
    u16 u[0x10][2];
    s16 s[0x10][2];
} D_800F5724_ovl20;

#endif
