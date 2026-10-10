#include "types.h"

s32 func_8004FD90(Obj800F2688* obj, s32 a1, s32 a2, s32 a3);

void func_800F5464_ovl27(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        func_8004FD90(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
