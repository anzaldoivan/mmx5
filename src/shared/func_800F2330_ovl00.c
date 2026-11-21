#include "types.h"
#include "mmx5/graphics.h"

void func_800F2330_ovl00(u8* o) {
    set_animation(o, 0);
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    *(s16*)(o + 0x7C) = 0x3C;
    o[6]++;
}
