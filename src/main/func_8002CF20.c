#include "types.h"
#include "mmx5/globals.h"

void func_8002CF20(void) {
    u8* p;
    s32 n;
    u8 z;

    z = 0;
    p = g_playthrough_state.u;
    n = 0x1BB;
    do {
        *p++ = z;
    } while (n--);
}
