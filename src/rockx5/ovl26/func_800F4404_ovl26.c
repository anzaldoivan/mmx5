#include "types.h"
#include "mmx5/globals.h"

void func_800F4404_ovl26(u8* o) {
    animate_object();
    *(s16*)(o + 0x7C) = 0x3C;
    o[6]++;
}
