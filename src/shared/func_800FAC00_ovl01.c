#include "types.h"
#include "mmx5/globals.h"

void func_800FAC00_ovl01(u8* obj) {
    if ((signed char)g_playthrough_state.u[0xF] == 0) {
        if ((signed char)g_playthrough_state.u[0xC] != 0xC) {
            s16* p = D_8009A1F8.h;
            p[0x12] = p[0x13] = 0x25B0;
            p[0x14] = p[0x15] = 0xF0;
        } else {
            s16* p = D_8009A1F8.h;
            p[0x12] = p[0x13] = 0x2B0;
        }
        if (--*(s16*)(obj + 0x7C) == 0) {
            obj[6] = 2;
        }
    }
}
