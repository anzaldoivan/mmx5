#include "types.h"
#include "mmx5/globals.h"

s32 get_launch_variant(void) {
    u8* p = g_playthrough_state.u;

    if (p[0x79] >= 5) {
        return 2;
    }
    return p[0xCB] & 1;
}
