#include "types.h"
#include "mmx5/globals.h"

extern void func_800F6C74_ovl01(u8* obj, s32 state);

void func_800F6B38_ovl01(u8* obj) {
    animate_object(obj);
    if (D_8009A0AA >= *(s16*)(obj + 0xA) - 0x5C) {
        *(s16*)(obj + 0x7C) = 0x5A;
        func_800F6C74_ovl01(obj, 1);
        obj[6]++;
    }
}
