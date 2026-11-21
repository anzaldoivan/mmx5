#include "types.h"

extern u8 D_80091C44;

void func_800F1A30_ovl20(UnkSpawn* arg0) {
    if (D_80091C44 == 0) {
        arg0->unk1 = 2;
        arg0->unk2 = 0;
    }
}
