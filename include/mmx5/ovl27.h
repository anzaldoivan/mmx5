#ifndef MMX5_OVL27_H
#define MMX5_OVL27_H

#include "types.h"

extern union {
    u8 u[0x80];
    Blk80 blk;
} D_800FDC18_ovl27;
extern union {
    u8 u[0x20];
    Blk20 blk;
} D_800FDD18_ovl27;
extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800FDD58_ovl27;
extern union {
    u8 u[0x20];
    Blk20 blk;
} D_800FE158_ovl27;

void func_800F59D8_ovl27();

#endif
