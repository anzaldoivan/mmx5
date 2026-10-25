#include "types.h"

extern u8 D_80091C44;
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

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
    func_80017248(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
