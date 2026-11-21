#include "types.h"
#include "mmx5/globals.h"

extern void (*D_80101BD0_ovl04[])(u8*);

void func_800F5494_ovl04(u8* arg0) {
    u8* g = g_Player;

    if (((signed char*)g)[0xF3] == 0) {
        D_80101BD0_ovl04[((signed char*)arg0)[6]](arg0);
    } else if ((u8)(g[0xFA] - 2) >= 2) {
        D_80101BD0_ovl04[((signed char*)arg0)[6]](arg0);
    }
}
