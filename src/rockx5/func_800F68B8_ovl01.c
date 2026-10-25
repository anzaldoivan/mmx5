#include "types.h"

extern void func_800F6C74_ovl01(u8* obj, s32 state);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void func_800F68B8_ovl01(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        if (*(s8*)(obj + 3) != 0) {
            func_800F6C74_ovl01(obj, 0);
        }
        obj[5] = 4;
        obj[6] = 0;
        func_800171E8(obj, 0);
    } else {
        func_80017248(obj);
    }
}
