#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F8C7C_ovl09(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        D_1F80004C.bytes[0x86] = 0;
        func_800171E8(obj, 0xD);
        obj[5] = 4;
        obj[6] = 0;
    }
}
