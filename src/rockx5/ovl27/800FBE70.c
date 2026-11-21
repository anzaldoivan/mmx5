#include "types.h"

#define D_800EEC60_ovl00 func_800FBE70_ovl27
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

void func_800FBE78_ovl27(u8* a0) {
    u8* p = *(u8**)(a0 + 0x7C);

    if (*(s8*)(p + 4) == 2) {
        a0[4]++;
    }
    *(s16*)(a0 + 0xA) = *(s16*)(p + 0xA);
    *(s16*)(a0 + 0xE) = *(s16*)(p + 0xE);
}
