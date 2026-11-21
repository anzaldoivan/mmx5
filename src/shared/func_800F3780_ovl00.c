#include "types.h"

void func_800F3780_ovl00(Obj0658* arg0) {
    if (arg0->unk15 != 0) {
        arg0->unk20 = 0x5000;
    } else {
        arg0->unk20 = -0x5000;
    }
    arg0->unk28 = 0x1000;
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    arg0->unk6++;
}
