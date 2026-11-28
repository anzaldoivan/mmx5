#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_80091C44;

void func_800FAB80_ovl58(u8* arg0) {
    if (D_80091C44 == 0) {
        if (!(D_8009A420_as_s32 & 1)) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
        }
        if (D_800D50DE >= 0x1F) {
            *(s16*)(arg0 + 4) = 0;
            arg0[1]++;
        }
    }
}
