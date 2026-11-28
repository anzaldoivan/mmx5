#include "types.h"
#include "mmx5/globals.h"

extern void func_80017B84(void);

void func_80020A3C(void) {
    s8* p = (s8*)g_playthrough_state.u;
    u8* q;

    if (p[0xC] == 12 && p[0x1D] >= 2 && p[0x1D] < 10) {
        return;
    }
    q = g_playthrough_state.u;
    if (q[0xC] != 9 && q[0xC] != 10) {
        func_80017B84();
    }
}
