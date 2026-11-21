#include "types.h"

extern u8 D_80091C44;

void func_800FA2B8_ovl47(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
