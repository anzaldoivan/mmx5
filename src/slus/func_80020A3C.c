#include "types.h"

extern u8 D_800D1C00[];
extern void func_80017B84(void);

void func_80020A3C(void) {
    s8* p = (s8*)D_800D1C00;
    u8* q;

    if (p[0xC] == 12 && p[0x1D] >= 2 && p[0x1D] < 10) {
        return;
    }
    q = D_800D1C00;
    if (q[0xC] != 9 && q[0xC] != 10) {
        func_80017B84();
    }
}
