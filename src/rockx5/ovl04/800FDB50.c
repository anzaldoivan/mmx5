#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_80102A64_ovl04[];
extern u8 D_80102A68_ovl04[];
extern u8 D_80102A6C_ovl04[];
extern u8 D_80102A70_ovl04[];
extern u8 D_80102A74_ovl04[];
extern u8 D_80076920[];

void func_800FDB50_ovl04(u8* p) {
    s8 t = ((s8*)p)[2];

    if (t == 1) {
        *(u8**)(p + 0x68) = D_80102A64_ovl04;
        *(u8**)(p + 0x54) = D_80102A68_ovl04;
    } else if (t == 9) {
        *(u8**)(p + 0x68) = D_80102A6C_ovl04;
        *(u8**)(p + 0x54) = D_80102A70_ovl04;
    } else {
        *(u8**)(p + 0x68) = D_80102A74_ovl04;
        p[0xA2] = 1;
    }
    *(u8**)(p + 0x58) = D_80076920;
    p[0x65] = 0;
    p[0x75] = 1;
    p[0x76] = 0;
    p[0x60] = 0x7F;
    p[0xA2] = 1;
    p[0x4]++;
}

#define D_800EEBA0_ovl00 func_800FDBE0_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
