#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2C30_ovl11(u8* obj) {
    s32 v;

    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        D_1F80004C.bytes[0x80] = 4;
        func_800171E8(obj, 9);
        v = 3;
        obj[5] = v;
        v = 0x4200;
        *(s32*)(obj + 0x2C) = v;
        v = -1;
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = v;
    }
}
