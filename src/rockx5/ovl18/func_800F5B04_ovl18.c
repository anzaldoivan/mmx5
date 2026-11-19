#include "types.h"
#include "mmx5/globals.h"

void func_800F5B04_ovl18(u8* arg0) {
    animate_object();
    if (*(s8*)(arg0 + 0x45) == 1) {
        arg0[3] = 0;
        arg0[6] = 0;
    }
}
