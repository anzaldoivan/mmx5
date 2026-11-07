#include "types.h"

extern s32 func_8003E6FC(void*, s8);
extern void func_8003CE10(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_80016D54(s32, s32);
extern void func_80016490(s32, s32, void*);
extern void func_80043DBC(u8* obj);

s32 func_80041B84(u8* obj) {
    if (*(s8*)(obj + 0x93) != 1) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x80) & 0x20)) {
        return 0;
    }
    if (*(s8*)(obj + 0xA6) != 0) {
        return 0;
    }
    if (*(s8*)(obj + 0x99) != 0) {
        return 0;
    }
    if (func_8003E6FC(obj, 1) > *(s16*)(obj + 0xAA)) {
        return 0;
    }
    func_8003CE10(obj);
    func_8003B33C(obj, 0x64);
    func_80016D54(0xFF, 0);
    func_80016490(1, 0x13, obj);
    obj[5] = 0x3F;
    obj[6] = 0;
    *(s16*)(obj + 0xAA) -= func_8003E6FC(obj, 1);
    func_80043DBC(obj);
    obj[0x98]++;
    obj[0x99]++;
    return 1;
}
