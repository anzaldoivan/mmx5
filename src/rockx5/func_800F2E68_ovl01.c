#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DED4(u8* obj);

void func_800F2E68_ovl01(u8* obj) {
    func_80017248(obj);
    if (obj[0x70] & 8) {
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 0;
        if (D_1F80004C.bytes[0x81] != 0) {
            func_800171E8(obj, 4);
            obj[6]++;
        } else {
            obj[5] = 2;
            obj[6] = 0;
        }
    } else {
        func_8002DED4(obj);
    }
}
