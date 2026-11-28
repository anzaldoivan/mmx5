#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_8002C1C8(void);

void func_800FAEDC_ovl58(u8* arg0) {
    if (!(D_8009A420_as_s32 & 1)) {
        D_800D50DE--;
        D_80093E68 -= 0x400;
        D_8009A42E -= 0x20;
    }
    if (D_800D50DE == 0) {
        func_8002C1C8();
        func_8002385C(0x66, 0xFF, 0);
        arg0[1]++;
    }
}
