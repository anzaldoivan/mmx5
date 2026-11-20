#include "types.h"
#include "mmx5/globals.h"

void func_800F5C58_ovl28(u8* o) {
    animate_object(o);
    if (*(s8*)(o + 0x45) == 1) {
        o[5] = 7;
        o[6] = 0;
        o[7] = 0;
    }
}
