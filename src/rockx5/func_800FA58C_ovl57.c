#include "types.h"

extern u8 D_800D1F3C;

void func_800FA58C_ovl57(Ovl45State* arg0) {
    if (D_800D1F3C == 2) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
