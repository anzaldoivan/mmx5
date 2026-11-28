#include "types.h"
#include "mmx5/globals.h"

void func_800FA1B0_ovl43(u8* a0) {
    u8* p;

    if (*(s16*)(a0 + 4) == 0) {
        func_8002385C(0xE, 0xFF, 0);
        p = D_8009A1F8.u;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0;
        p[0xF4] = 1;
        p[0xAB] = 1;
        *(s16*)(p + 0x5E) = 0xC0;
        *(s16*)(p + 0x62) = 8;
        p[0xA0] = 1;
        p[0x57] = 1;
        *(s16*)(a0 + 4) = 0;
        a0[1]++;
    }
}
