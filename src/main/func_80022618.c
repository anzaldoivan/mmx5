/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800206C0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

extern int func_8002DAA0();

void func_80022618(void) {
    s8* p;

    for (D_1F800064 = D_800D1F40.s; D_1F800064 < D_800D1F40.s + 0x3000;
         D_1F800064 += 0x60) {
        if (g_playthrough_state.s[0x17] == 0) {
            p = D_1F800064;
            if (p[0] == 0) {
                continue;
            }
            goto call; // !FAKE: control flow kept from the mmx6 twin
        } else {
            p = D_1F800064;
            if (p[0] != 0) {
                if ((u8)p[0] & 8) {
                call:
                    D_1F800090[p[1]](p);
                } else if (p[3] != 0) {
                    func_8002DAA0(p);
                }
            }
        }
    }
}
