#include "types.h"

extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);

void func_800F1A5C_ovl09(u8* obj) {
    if (*(s32*)(obj + 0x24) <= -0x80000) {
        *(s32*)(obj + 0x24) = -0x80000;
    }
    func_8002DED4(obj);
    func_8002FB58(obj);
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 0;
        if (obj[0x15] == 0) {
            obj[0x8F] = 0;
            obj[5] = 2;
        } else {
            obj[0x8F] = 1;
            obj[5] = 3;
        }
        obj[6] = 0;
    }
}
