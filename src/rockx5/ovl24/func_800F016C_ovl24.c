#include "types.h"

extern s8 D_8009A424;
extern u16 D_800F4E60_ovl24[];
extern u16 D_800F5F74_ovl24;
extern s16 D_800F5F76_ovl24;

void func_800F016C_ovl24(u8* self) {
    s8 i = D_8009A424;

    if (i == 0) {
        D_800F5F76_ovl24 = 0;
        D_800F5F74_ovl24 = D_800F4E60_ovl24[i >> 31];
        self[2]++;
    }
}
