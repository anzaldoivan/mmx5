#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800EFAF8_ovl18(u8* o) {
    animate_object(o);
    if (*(s8*)(o + 0x46) == 0) {
        o[0x16] = 1;
        set_animation(o, 3);
        o[5]++;
    }
}
