#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);

void func_800F6BBC_ovl28(u8* obj) {
    func_80017248(obj);
    func_800317B8(obj);
    func_8002D9EC(obj, 0x20, 0x14);
    if (*(s8*)(obj + 0x45) == 1) {
        func_800171E8(obj, 0x11);
        obj[5]++;
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}
