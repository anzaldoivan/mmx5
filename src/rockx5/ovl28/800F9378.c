#include "types.h"
#include "mmx5/graphics.h"

void func_800F9378_ovl28(u8* obj) {
    set_animation(obj, 2);
    obj[0x85] = 0x3C;
    if (((s8*)obj)[2] == 1) {
        obj[0x85] = 0x64;
    }
    obj[6]++;
}

void func_800F93C8_ovl28(u8* arg0) {
    s32 v;

    v = arg0[0x85] - 1;
    arg0[0x85] = v;
    if ((v & 0xFF) == 0xFF) {
        arg0[6]++;
    }
}

#define D_800EEC60_ovl00 func_800F93FC_ovl28
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
