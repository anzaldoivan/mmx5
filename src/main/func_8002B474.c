#include "types.h"
#include "mmx5/globals.h"

extern u8* D_80072EAC[][2];

void func_8002B474(void) {
    u8* p = D_80072EAC[g_playthrough_state.s[0xC]][g_playthrough_state.s[0xD]];

    while (p[3] != 0xF) {
        p[3] &= 0xF;
        p[0] &= 0x70;
        p += 8;
    }
}
