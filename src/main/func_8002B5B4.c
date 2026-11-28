#include "types.h"
#include "mmx5/globals.h"

extern u8* D_80072DD4[][2];

u8 func_8002B5B4(u8 arg0) {
    u8* p = D_80072DD4[g_playthrough_state.s[0xC]][g_playthrough_state.s[0xD]];
    u8 i;
    u8 c;

    for (i = 0;; i++) {
        c = p[i];
        if (c == 0xFF || c == arg0) {
            return i;
        }
    }
}
