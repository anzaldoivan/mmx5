#include "types.h"
#include "mmx5/globals.h"

void func_800F5464_ovl27(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        ((s32(*)())func_8004FD90)(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
