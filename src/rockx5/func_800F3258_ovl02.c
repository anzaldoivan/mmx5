#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);

void func_800F3258_ovl02(u8* obj) {
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) > 0x20000) {
        *(s32*)(obj + 0x2C) = 0;
    }
    if (obj[0x70] & 8) {
        func_80016490(5, 8, obj);
        func_800171E8(obj, 2);
        obj[0x67] = 0;
        obj[6]++;
    }
}
