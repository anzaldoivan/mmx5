/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80020378.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"

#define M2C_UNK s32

M2C_UNK func_8002DAA0(void*);
extern u8 D_80094398[];
extern X4_EngineObj D_800D1C00;

void func_800222D0(void) {
    s8* p;

    for (D_1F800054 = (s8*)D_80094398; D_1F800054 < (s8*)(D_80094398 + 0x2A00);
         D_1F800054 += 0x70) {
        if (D_800D1C00.unk14 == 0) {
            p = D_1F800054;
            if (p[0] == 0) {
                continue;
            }
            goto call; // !FAKE: jump into else arm; matches the shared call site
        } else {
            p = D_1F800054;
            if (p[0] != 0) {
                if ((u8)p[0] & 8) {
                call:
                    D_1F800088[p[1]](p);
                } else if (p[3] != 0) {
                    func_8002DAA0(p);
                }
            }
        }
    }
}
