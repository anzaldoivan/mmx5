#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800FEE80_ovl04(void) {
    g_playthrough_state.u[0x26] |= 4;
    clear_object_slot();
}
