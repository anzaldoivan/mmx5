#include "types.h"
#include "mmx5/globals.h"

void func_800F2258_ovl00(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        obj->unk7C = 2;
        obj->unk4 = 3;
    } else if (--obj->unk7E == 0) {
        obj->pad0[3] = 0;
        func_8004FD90(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
