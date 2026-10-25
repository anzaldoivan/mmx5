#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2AC0_ovl11(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        if (D_1F80004C.bytes[0x80] == 4) {
            func_800171E8(obj, 0x17);
        } else {
            func_800171E8(obj, 0x18);
        }
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
    }
}
