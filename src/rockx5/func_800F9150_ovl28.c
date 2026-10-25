#include "types.h"

extern void func_80016D54(s32, s32);
extern void func_80044DD0(s32 a0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F9150_ovl28(u8* obj) {
    if (obj[0x70] & 8) {
        func_80016D54(2, 0x90);
        func_80044DD0(0);
        func_800171E8(obj, 2);
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DF54(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}
