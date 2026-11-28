#include "types.h"
#include "mmx5/globals.h"

void func_800FA390_ovl47(u8* arg0) {
    D_800D50DE++;
    D_8009A42E += 0x20;
    D_80093E68 += 0x400;
    if (D_800D50DE == 0x1F) {
        u8* p = D_8009A1F8.u;
        p[0x57] = 0;
        *(s16*)(p + 0xB6) = 0x100;
        p[0xF4] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
