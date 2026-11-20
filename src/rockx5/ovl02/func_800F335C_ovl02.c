#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C26;

void func_800F335C_ovl02(u8* obj) {
    animate_object(obj);
    func_8002D9EC(obj, 0x20, 0x20);
    if (D_800D1C26 == 0) {
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
}
