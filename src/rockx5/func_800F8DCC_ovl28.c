#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800FE378_ovl28[];
extern u8 D_800D1C00[];

void func_800F8DCC_ovl28(u8* obj) {
    if (*(s16*)(obj + 0xE) >= 0x2A0) {
        *(u8**)(obj + 0x68) = D_800FE378_ovl28;
    }
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s8*)(obj + 0x46) == 0) {
        u8* p = D_800D1C00;
        func_8002385C(0x44, 0xFF, ((s8*)p)[0x2E]);
        p[0x2E] = 1;
        func_800171E8(obj, 2);
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DF54(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}
