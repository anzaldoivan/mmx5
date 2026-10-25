#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800F6C74_ovl01(u8* obj, s32 state);
extern s16 D_8009A0AA;

void func_800F6B38_ovl01(u8* obj) {
    func_80017248(obj);
    if (D_8009A0AA >= *(s16*)(obj + 0xA) - 0x5C) {
        *(s16*)(obj + 0x7C) = 0x5A;
        func_800F6C74_ovl01(obj, 1);
        obj[6]++;
    }
}
