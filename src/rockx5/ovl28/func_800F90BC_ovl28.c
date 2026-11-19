#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800F90BC_ovl28(u8* obj) {
    if (D_80091C44 == 0) {
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
    if (++*(s16*)(obj + 0x7C) == 0x20) {
        *(s16*)(obj + 0x7C) = 0;
        *(s32*)(obj + 0x2C) = -*(s32*)(obj + 0x2C);
    }
    *(s32*)(obj + 0xC) += *(s32*)(obj + 0x2C);
    animate_object(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
