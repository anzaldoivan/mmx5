#include "types.h"

/* e: UnkObj (include/types.h): unk1, unk4, unk6 */
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_800FB0D0_ovl52[];
extern u8 D_8009A298;

void func_800FAD50_ovl52(UnkObj* e) {
    if (e->unk6 < 30) {
        e->unk6++;
        return;
    }
    if (++e->unk4 >= 8) {
        func_80028B18(1, 0x340, 0x240, D_800FB0D0_ovl52);
        D_8009A298 = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}
