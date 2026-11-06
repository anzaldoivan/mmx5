#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern u8 D_80076E54[];
extern u8 D_80076E58[];
extern u8 D_8007B490[];

void func_8004616C(u8* obj) {
    u8* p;
    u8* q;
    s32 t;

    obj[0] = 1;
    obj[3] = 1;
    obj[0x64] = 1;
    *(u8**)(obj + 0x50) = D_80076E54;
    *(u8**)(obj + 0x68) = D_80076E58;
    p = D_1F800014;
    *(u8**)(obj + 0x38) = p + *(s32*)(p + 0x2C);
    q = D_1F80001C.bytes;
    t = *(s32*)(q + 0x18);
    *(u8**)(obj + 0x30) = D_8007B490;
    *(s16*)(obj + 0x40) = 0x540;
    *(s16*)(obj + 0x42) = 0x7802;
    obj[0x16] = 1;
    *(u8**)(obj + 0x3C) = q + t;
    if (obj[0x15] != 0) {
        *(s32*)(obj + 0x20) = 0xA0000;
    } else {
        *(s32*)(obj + 0x20) = -0xA0000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    func_800171E8(obj, 0);
    obj[5] = 0;
    obj[4]++;
    func_8003D4C0(1, 0x1B, 7, 0);
}
