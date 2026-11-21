#include "types.h"
#include "mmx5/graphics.h"

void func_800F0B30_ovl12(Obj800EFBC4* arg0) {
    if (++arg0->unk7C == 20) {
        set_animation(arg0, 10);
        if (arg0->unk15 != 0) {
            arg0->unk20 = -0x80000;
        } else {
            arg0->unk20 = 0x80000;
        }
        arg0->unk24 = 0x20000;
        arg0->unk2C = 0x1999;
        arg0->unk6++;
    }
}
