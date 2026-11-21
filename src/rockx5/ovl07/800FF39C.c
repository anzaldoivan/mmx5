#include "types.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800FF39C_ovl07
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

void func_800FF3BC_ovl07(u8* p) {
    s16* t = (s16*)(p + 0x7C);

    if (--t[0] == 0) {
        p[4] = 2;
    } else if ((t[1] = *(s16*)(p + 0x7E) - 1) == 0) {
        if (((s8*)p)[2] == 0) {
            func_8004FD90(p, 1, 0x10, 0x20);
        } else {
            func_8004FD90(p, 1, 8, 0x20);
        }
        *(s16*)(p + 0x7E) = 5;
    }
}
