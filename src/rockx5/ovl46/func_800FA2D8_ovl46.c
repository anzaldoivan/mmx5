#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FA2D8_ovl46(u8* arg0) {
    if (!(D_8009A420_as_s32 & 3)) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE >= 0x1F) {
        func_8002385C(0x1A, 0xFF, 0);
        arg0[1]++;
    }
}
