#ifndef MMX5_OVL56_H
#define MMX5_OVL56_H

#include "types.h"

extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800FBF00_ovl56;
extern union {
    u8 u[0x200];
    Blk200 blk;
} D_800FC300_ovl56;

extern u8 D_800FC700_ovl56[];
extern u8 D_800FCB00_ovl56[];
extern u8 D_800FCF00_ovl56[];
extern u8 D_800FD300_ovl56[];
extern u8 D_800FD700_ovl56[];
extern u8 D_800FDB00_ovl56[];

#endif
