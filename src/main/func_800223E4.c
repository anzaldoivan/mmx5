#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800223E4(void) {
    for (D_1F80005C = (s8*)g_class3_slots.u;
         D_1F80005C < (s8*)g_class3_slots.u + 0x1200; D_1F80005C += 0x30) {
        if (g_playthrough_state.s[0x15] == 0) {
            if (D_1F80005C[0]) {
                D_1F80008C[D_1F80005C[1]](D_1F80005C);
            }
        } else if ((u8)D_1F80005C[0] & 8) {
            D_1F80008C[D_1F80005C[1]](D_1F80005C);
        }
    }
}
