#include "types.h"
#include "mmx5/globals.h"

void func_800234CC(void) {
    u8* p = 0x801F600C;

    g_playthrough_state.u[0x44] = p[0x44];
    g_playthrough_state.u[0x49] = p[0x49];
    g_playthrough_state.u[0xC] = p[0xC];
    g_playthrough_state.u[0xD] = p[0xD];
}
