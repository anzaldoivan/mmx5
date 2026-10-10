#include "types.h"

extern u8 D_8009A0A0[];
s32 func_8004FD90(Obj800F2688* obj, s32 a1, s32 a2, s32 a3);

void func_800F255C_ovl04(Obj800F2688* obj) {
    if (((s8*)obj)[5] == 4) {
        D_8009A0A0[0xCA] = 0;
        if (D_8009A0A0[0x5C] & 0x7F) {
            D_8009A0A0[3] = 1;
        }
    }
    if (--obj->unk7C == 0) {
        obj->unk7C = 2;
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        func_8004FD90(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
