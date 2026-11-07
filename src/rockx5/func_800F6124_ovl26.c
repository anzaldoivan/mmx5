#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void func_800F6124_ovl26(u8* obj) {
    func_80017248(obj);
    if (*(s16*)(obj + 0x90) != 0) {
        *(s16*)(obj + 0x90) -= 1;
        return;
    }
    if (obj[0x94] < 3) {
        obj[5] = 0;
        func_80016490(2, 0x5E, obj);
        func_800171E8(obj, 1);
    } else {
        obj[5] = 5;
        if (*(s8*)(obj + 2) < 8) {
            func_800171E8(obj, 1);
            func_80016490(2, 0x5E, obj);
        }
    }
    obj[6] = 0;
    if ((*(u8**)(obj + 0x7C))[0x96]) {
        *(s32*)(obj + 0x20) = 0x60000;
    } else {
        *(s32*)(obj + 0x20) = 0xFFFA0000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    (*(u8**)(obj + 0x7C))[0x97] = 0;
}
