#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 arg1);

void func_800F5CD4_ovl28(u8* o) {
    func_80017248(o);
    func_800171E8(o, 1);
    *(s16*)(o + 0x7C) = 0x3C;
    o[6]++;
}
