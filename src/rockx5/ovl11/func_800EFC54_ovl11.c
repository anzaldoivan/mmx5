#include "types.h"

extern u8 D_800D1C00[];

void func_800EFC54_ovl11(u8 arg0) {
    D_800D1C00[0x10] = arg0;
    D_800D1C00[0x11] = arg0;
    D_800D1C00[0x12] = arg0;
    D_800D1C00[0x13] = arg0;
    D_800D1C00[0x16] = arg0;
}
