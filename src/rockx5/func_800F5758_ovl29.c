#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8003D29C(s32, s32);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0B5;

void func_800F5758_ovl29(u8* obj) {
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x61] = 0x19;
    obj[5]++;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    func_800171E8(obj, 0xD);
    func_8003D29C(0x14, D_8009A0B5);
    func_8002D9EC(obj, 0x40, 0x40);
}
