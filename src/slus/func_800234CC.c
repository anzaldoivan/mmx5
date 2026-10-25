#include "types.h"

extern u8 D_800D1C00[];

void func_800234CC(void) {
    u8* p = 0x801F600C;

    D_800D1C00[0x44] = p[0x44];
    D_800D1C00[0x49] = p[0x49];
    D_800D1C00[0xC] = p[0xC];
    D_800D1C00[0xD] = p[0xD];
}
