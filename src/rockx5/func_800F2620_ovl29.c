#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void func_800F2620_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        func_800171E8(obj, 1);
        obj[5] = 3;
        obj[6] = 0;
    }
    func_80017248(obj);
}
