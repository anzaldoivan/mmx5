#include "types.h"

extern void func_80054440(u8* a0, s32 a1);
void func_8004FD90(Obj800F2688* obj, s32 a1, s32 a2, s32 a3);

void func_800F08BC_ovl11(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        func_80054440((u8*)obj, 8);
        obj->unk4++;
    } else if (--obj->unk7E == 0) {
        func_8004FD90(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
