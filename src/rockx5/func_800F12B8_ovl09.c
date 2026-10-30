#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F12B8_ovl09(u8* obj) {
    func_800171E8(obj, 0);
    *(s16*)(obj + 0x7C) = 0x78;
    obj[6]++;
}
