#include "types.h"
#include "mmx5/globals.h"

#define D_800FA214_ovl00 D_80073398

#define func_800EEB64_ovl00 func_80034A48
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

extern u16 D_800C9320;
extern void (*D_800733A4[])(u8*);

void func_80034A84(u8* a0) {
    s32 s;
    s32 t;

    if (D_800C9320 & 0x100) {
        t = ((s8*)a0)[5];
        if (t < 3) {
            *(s32*)(a0 + 0x30) = t;
            a0[5] = 6;
            a0[6] = 0;
        }
    }
    s = ((s8*)a0)[5];
    D_800733A4[s](a0);
    if (s != 7) {
        if (((s8*)a0)[5] < 5) {
            func_800272DC();
        }
        if (((s8*)a0)[5] == 7) {
            func_800272DC();
        }
    }
}

#define D_800FA214_ovl00 D_800733F4

#define func_800EEB64_ovl00 func_80034B48
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
