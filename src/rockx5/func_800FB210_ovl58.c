#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;

void func_800FB210_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.pad0[3] = 0;
        D_8009A1F8.unk57 = 1;
        D_8009A1F8.unk5E = 0;
        D_8009A1F8.unk62 = 0x560;
        D_8009A1F8.unkA0 = 1;
        arg0->unk1++;
    }
}
