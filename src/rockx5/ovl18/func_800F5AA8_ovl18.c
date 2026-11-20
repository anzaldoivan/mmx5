#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F5AA8_ovl18(u8* o) {
    animate_object(o);
    if (--o[0x7C] == 0) {
        set_animation(o, 2);
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        o[6]++;
    }
}
