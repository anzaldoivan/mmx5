#include "types.h"

extern u8* D_80072EAC[][2];
extern s8 D_800D1C00[];

void func_8002B474(void) {
    u8* p = D_80072EAC[D_800D1C00[0xC]][D_800D1C00[0xD]];

    while (p[3] != 0xF) {
        p[3] &= 0xF;
        p[0] &= 0x70;
        p += 8;
    }
}
