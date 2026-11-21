#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F0E9C_ovl28(Obj0E9C* arg0) {
    arg0->unk67 = 0;
    arg0->unk6++;
    if ((arg0->unk2 & 0xF) == 2) {
        arg0->unk20 = 0;
    } else {
        s32 v = -0x40000;
        if (arg0->unk15 != 0) {
            v = 0x40000;
        }
        arg0->unk20 = v;
    }
    arg0->unk28 = 0;
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    set_animation(arg0, 0);
    D_1F80004C.ctx0f18->unk80 = 0x3C;
}
