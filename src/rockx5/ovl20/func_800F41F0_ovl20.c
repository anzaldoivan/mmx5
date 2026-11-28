#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_800F5904_ovl20[])(u8*);

void func_800F41F0_ovl20(u8* arg0) {
    D_800F5904_ovl20[((s8*)arg0)[4]](arg0);
    arg0[0x54] = g_playthrough_state.u[0x2A];
    if (((s8*)g_playthrough_state.u)[0x31] != 0) {
        clear_object_slot(arg0);
    }
}
