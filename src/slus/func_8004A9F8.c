#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8003D430(s32, s32, s32, void*);
extern s32 D_800771C8[];
extern s32 D_800771EC[];

void func_8004A9F8(u8* obj) {
    s32 x;
    u8 state;
    s16 n;
    s16 q;
    s32 t;

    func_80017248(obj);
    func_8002DF54(obj);
    x = *(s32*)(obj + 0x20) + *(s32*)(obj + 0x28);
    *(s32*)(obj + 0x20) = x;
    *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) + *(s32*)(obj + 0x2C);
    if (x > 0x40000) {
        *(s32*)(obj + 0x20) = 0x40000;
    }
    if (*(s32*)(obj + 0x20) < -0x40000) {
        *(s32*)(obj + 0x20) = -0x40000;
    }
    if (*(s32*)(obj + 0x24) > 0x40000) {
        *(s32*)(obj + 0x24) = 0x40000;
    }
    if (obj[0x70] != 0 || (func_8002F8FC(obj), obj[0x70] != 0)) {
        func_800171E8(obj, 1);
        state = 2;
        goto clear; // !FAKE: goto kept for the matching branch layout
    }
    func_8002D9EC(obj, 0x40, 0xA0);
    if (*(s8*)(obj + 3) == 0) {
        state = 3;
    clear:
        obj[4] = state;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x68) = 0;
        return;
    }
    t = *(u16*)(obj + 0x8C) + 1;
    n = t;
    *(u16*)(obj + 0x8C) = t;
    if (n < 0x29 && n % 10 == 0) {
        func_8003D430(1, *(s8*)(obj + 1), (s8)(n / 10), obj);
        q = *(s16*)(obj + 0x8C) / 10;
        *(s32**)(obj + 0x50) = &D_800771C8[q];
        *(s32**)(obj + 0x68) = &D_800771EC[q];
    }
}
