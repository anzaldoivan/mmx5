/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80025F34.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/144A4.c:func_80023CE0, AGPL-3.0; proven shared with X6 by exact signature 6affe00825b4 (see THIRD_PARTY.md). */
#include "types.h"
extern int func_800276C4();
extern int func_800287F0();
extern X4_EngineObj D_800D1C00;
extern u8 D_800717FC[16][2];

void func_80027238() {
    func_800276C4(0, D_800717FC[D_800D1C00.stage][D_800D1C00.substage]);
    func_800287F0();
}
