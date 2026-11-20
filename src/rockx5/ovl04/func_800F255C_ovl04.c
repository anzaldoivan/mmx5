#include "types.h"
#include "mmx5/globals.h"

void func_800F255C_ovl04(Obj800F2688* obj) {
    if (((s8*)obj)[5] == 4) {
        g_Player[0xCA] = 0;
        if (g_Player[0x5C] & 0x7F) {
            g_Player[3] = 1;
        }
    }
    if (--obj->unk7C == 0) {
        obj->unk7C = 2;
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        ((s32(*)())func_8004FD90)(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
