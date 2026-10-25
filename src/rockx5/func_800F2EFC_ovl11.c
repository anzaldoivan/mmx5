#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2EFC_ovl11(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        func_800171E8(obj, 0xB);
        obj[6]++;
    }
}
