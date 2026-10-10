#include "types.h"

extern void func_80054440(u8* a0, s32 a1);
void func_8004FD90(Obj800F2688* obj, s32 a1, s32 a2, s32 a3);

void func_800F64B4_ovl01(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        func_80054440((u8*)obj, 0x12);
        obj->unk4 = 6;
    } else if (--obj->unk7E == 0) {
        func_8004FD90(obj, 1, 0x10, 0x10);
        obj->unk7E = 5;
    }
}
