#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F5CD4_ovl28(u8* o) {
    animate_object(o);
    set_animation(o, 1);
    *(s16*)(o + 0x7C) = 0x3C;
    o[6]++;
}
