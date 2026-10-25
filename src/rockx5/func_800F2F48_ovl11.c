#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2F48_ovl11(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        if (D_1F80004C.bytes[0x85] != 2) {
            obj[5] = 5;
        } else {
            obj[5] = 7;
        }
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        D_1F80004C.bytes[0x81] = 0;
        if (D_1F80004C.bytes[0x85] == 2) {
            D_1F80004C.bytes[0x83] = 0x5A;
        } else {
            D_1F80004C.bytes[0x83] = 0xB4;
        }
        func_800171E8(obj, 7);
    }
}
