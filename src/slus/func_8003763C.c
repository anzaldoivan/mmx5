#include "types.h"

extern void func_8002DED4(Obj76EC*);

void func_8003763C(Obj76EC* arg0) {
    if (arg0->unkD4 != 0) {
        return;
    }
    if (arg0->unk20 != 0) {
        s32 mask;
        if (arg0->unk20 > 0) {
            mask = 1;
        } else {
            mask = 2;
        }
        if (arg0->unk89 & mask) {
            arg0->unk20 = 0;
            arg0->unk28 = 0;
        }
    }
    func_8002DED4(arg0);
    if (arg0->unk15 != 0) {
        if (arg0->unk20 > 0) {
            arg0->unk20 = 0;
            arg0->unk28 = 0;
        }
    } else if (arg0->unk20 < 0) {
        arg0->unk20 = 0;
        arg0->unk28 = 0;
    }
}
