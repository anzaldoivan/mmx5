/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800207D4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"

extern u8 D_8009F9A0[];
extern X4_EngineObj D_800D1C00;

void func_8002272C(void) {
    for (D_1F800068 = (s8*)D_8009F9A0; D_1F800068 < (s8*)D_8009F9A0 + 0x1800;
         D_1F800068 += 0x60) {
        if (D_800D1C00.unk18 == 0) {
            if (D_1F800068[0]) {
                D_1F800098[D_1F800068[1]](D_1F800068);
            }
        } else if (D_1F800068[0] && (u8)D_1F800068[0] & 8) {
            D_1F800098[D_1F800068[1]](D_1F800068);
        }
    }
}
