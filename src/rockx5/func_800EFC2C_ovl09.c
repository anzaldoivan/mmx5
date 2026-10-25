#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800EFC2C_ovl09(u8* obj) {
    if (*(s16*)(obj + 0x7E) != 0) {
        *(s16*)(obj + 0x7E) = *(s16*)(obj + 0x7E) - 1;
        return;
    }
    func_800171E8(obj, 1);
    *(s16*)(obj + 0x7E) = 0x3C;
    obj[6] = 0;
}
