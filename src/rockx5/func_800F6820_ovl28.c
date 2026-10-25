#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 D_8009A0A8;

void func_800F6820_ovl28(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 7) == 2) {
        func_800171E8(obj, 4);
        D_1F80004C.bytes[0x8C] = 0;
        func_80017248(obj);
        obj[0x67] = 1;
        if (D_8009A0A8 > *(s32*)(obj + 8)) {
            *(s32*)(obj + 0x20) = -0x20000;
            obj[0x15] = 0;
        } else {
            *(s32*)(obj + 0x20) = 0x20000;
            obj[0x15] = 0x40;
        }
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x5D000;
        *(s32*)(obj + 0x2C) = 0x4200;
        obj[6]++;
    }
}
