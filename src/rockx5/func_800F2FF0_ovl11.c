#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F2FF0_ovl11(u8* obj) {
    if (*(s8*)(obj + 5) == 2) {
        if (++D_1F80004C.bytes[0x81] == 90) {
            obj[5] = 5;
            obj[6] = 0;
            D_1F80004C.bytes[0x81] = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x20) = 0;
            func_800171E8(obj, 7);
        }
    }
}
