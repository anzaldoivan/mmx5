#include "types.h"
#include "mmx5/globals.h"

void func_800F2528_ovl20(u8* arg0) {
    if ((*(s32*)g_playthrough_state.u & 0xFFFF00) == 0x400) {
        arg0[4]--;
    }
}
