#include "types.h"
#include "mmx5/globals.h"

void func_800F81F4_ovl11(Obj800F81F4* arg0) {
    if (arg0->unkA > D_8009A0AA) {
        arg0->unk15 = 0;
        arg0->unk20 = -1;
    } else {
        arg0->unk15 = 0x40;
        arg0->unk20 = 1;
    }
}
