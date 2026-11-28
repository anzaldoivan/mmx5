#ifndef MMX5_OVL58_H
#define MMX5_OVL58_H

#include "types.h"

extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800FB600_ovl58;
extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800FBA00_ovl58;
extern union {
    u8 u[0x20];
    Blk20 blk;
} D_800FBE00_ovl58;
extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800FBE40_ovl58;

#endif
