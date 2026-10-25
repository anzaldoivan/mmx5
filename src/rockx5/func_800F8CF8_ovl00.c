#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F8CF8_ovl00(u8* obj) {
    func_800171E8(obj, 4);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s16*)(obj + 0x7C) = 15;
    obj[6]++;
    func_80016490(2, 4, obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
