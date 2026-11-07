#include "types.h"
#include "addr.h"

extern void func_80045D44();
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_80076FC8[];
extern u8 D_80076FD0[];
extern u8 D_8007B414[];
extern u8 D_8009A0A0[];

void func_8004753C(u8* obj) {
    u8* s;
    s32 t;
    s32 one;

    obj[3] = 1;
    *(u8**)(obj + 0x50) = D_80076FC8;
    *(u8**)(obj + 0x68) = D_80076FD0;
    obj[0x64] = 0;
    *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0xC);
    s = D_1F80001C.bytes;
    t = *(s32*)(s + 0x2C);
    *(u8**)(obj + 0x30) = D_8007B414;
    *(s16*)(obj + 0x40) = 0x520;
    *(s16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 0;
    *(u8**)(obj + 0x3C) = s + t;
    obj[0x15] = D_8009A0A0[0x15];
    func_80045D44(obj, D_8009A0A0, *(s8*)(obj + 1), t);
    one = 1;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = 0xFFFB0000;
    } else {
        *(s32*)(obj + 0x20) = 0x50000;
    }
    *(s32*)(obj + 0x24) = 0xFFFB8000;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = one;
    func_800171E8(obj, 0);
    func_80016490(1, 0x14, obj);
    obj[5] = 0;
    obj[4]++;
    func_8002D9EC(obj, 0x2C, 0x20);
}
