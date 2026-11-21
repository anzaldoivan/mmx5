#include "types.h"
#include "mmx5/globals.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800F52B4_ovl05[];

void func_800EFE4C_ovl05(u8* arg0) {
    func_8004D4F4(6, D_800F52B4_ovl05, arg0);
    arg0[3] = 0;
    *(s16*)(arg0 + 0x7C) = 0xF;
    *(s16*)(arg0 + 0x7E) = 5;
    arg0[4] = 5;
}

void func_800EFE98_ovl05(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        ((s32(*)())func_8004FD90)(obj, 1, 0x20, 0x10);
        obj->unk7E = 5;
    }
}
