#include "types.h"
#include "mmx5/object.h"

void func_800F8DB8_ovl09(u8* o) {
    move_object(o);
    if (*(s16*)(o + 0xE) < 0x821) {
        o[4] = 4;
        o[5] = 0;
        o[6] = 0;
    }
}
