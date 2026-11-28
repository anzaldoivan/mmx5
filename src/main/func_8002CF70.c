#include "types.h"
#include "mmx5/object.h"

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
        p = g_projectiles.r[i];
        n = 0x9C;
        while (n--) {
            *p++ = z;
        }
    }
}
