#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];

void func_800F16C4_ovl07(u8* arg0) {
    u8* p = D_8009A0A0;
    s16 y;

    if (*(u16*)(p + 0xA) >= 0x20C0 && *(u16*)(p + 0xA) <= 0x21C0) {
        y = *(s16*)(p + 0xE);
        if (y >= 0x4D0) {
            if (y < 0x511) {
                D_8009A1F8[0xAC] = 0xB;
                *(s16*)(D_8009A1F8 + 0xE8) = 0;
                *(s16*)(D_8009A1F8 + 0xEA) = -0x238;
                D_8009A1F8[0xF4] = 1;
                arg0[4]++;
            }
        }
    }
}
