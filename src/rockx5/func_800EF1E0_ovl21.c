#include "types.h"

extern u8 D_800D1F3C;
extern signed char D_8009A424;
extern u8 D_800D1C00[];
extern void func_8001E668(void);

void func_800EF1E0_ovl21(u8* a0) {
    s32 i;
    u8* p;

    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        a0[0xC] = D_800D1C00[0x26];
        a0[0xD] = D_800D1C00[0x27];
        a0[0] = 7;
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
        for (i = 15, p = a0 + 0x35; i >= 0; i--) {
            *p-- = 0;
        }
    }
}
