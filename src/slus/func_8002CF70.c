#include "types.h"

extern u8 D_80092090[];
extern u8 D_80096D98[][0x9C];

void func_8002CF70(void) {
    u8* p;
    s32 n;
    u32 i;
    u8 z = 0;

    for (i = 0; i < 48; i++) {
        p = D_80092090 + i * 0x9C;
        n = 0x9C;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 32; i++) {
        p = D_80096D98[i];
        n = 0x9C;
        while (n--) {
            *p++ = z;
        }
    }
}
