#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_8002DC44(void) {
    Obj8002CC08* p;
    u8* q;
    s32 n;
    u32 i;
    s32 z;

    z = 0;
    for (i = 0; i < 32; i++) {
        p = &D_80098120.cc08[i];
        if (p->active == 0 || ((s8*)p)[1] != 0x37) {
            q = (u8*)p;
            n = sizeof(Obj8002CC08) - 1;
            do {
                *q++ = z;
            } while (n--);
        }
    }
    g_Player[0x99] = 0;
    g_Player[0x98] = 0;
    g_Player[0xA6] = 0;
}
