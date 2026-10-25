#include "types.h"

void func_8002DED4(u8* obj);

void func_800F48F4_ovl06(u8* obj) {
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x20) > 0) {
        *(s16*)(obj + 0x7C) = 0x14;
        obj[6]++;
    }
}
