#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F32D0_ovl02(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        func_800171E8(obj, 3);
        obj[5] = 4;
        obj[6] = 0;
        obj[0x60] = 0x7F;
    }
}
