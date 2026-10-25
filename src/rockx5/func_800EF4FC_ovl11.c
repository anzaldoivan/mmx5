#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800EF4FC_ovl11(u8* obj) {
    obj[3] = 1;
    *(s16*)(obj + 0x54) = 0;
    obj[4]++;
    func_800171E8(obj, 3);
}
