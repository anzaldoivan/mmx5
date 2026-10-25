#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_800F2F44_ovl01(u8* arg0);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2D00_ovl01(u8* obj) {
    s8 f;

    func_80017248(obj);
    func_8002DED4(obj);
    func_800F2F44_ovl01(obj);
    f = *(s8*)(obj + 0x45);
    if (f != 0) {
        func_800171E8(obj, 2);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[5] = 3;
        obj[6] = 0;
        obj[0x15] ^= 0x40;
    }
}
