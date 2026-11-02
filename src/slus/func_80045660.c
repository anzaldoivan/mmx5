#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern int func_80045D44();
extern u8 D_80076E60[];
extern u8 D_80076E64[];
extern u8 D_80076E68[];
extern u8 D_80076E6C[];
extern u8 D_8007B49C[];

void func_80045660(u8* obj) {
    u8* src;
    u8* p;
    u8* q;

    obj[0] = 1;
    *(u8**)(obj + 0x30) = D_8007B49C;
    obj[3] = 1;
    obj[0x16] = 1;
    src = *(u8**)(obj + 0x7C);
    if (*(s8*)(obj + 1) == 0x2D) {
        obj[0x15] = src[0x15];
        func_80045D44(obj, src, 0x2D);
        *(u8**)(obj + 0x68) = D_80076E64;
        *(u8**)(obj + 0x50) = D_80076E60;
        *(s16*)(obj + 0x40) = 0x520;
        p = D_1F80001C.bytes;
        p += *(s32*)(p + 0x1C);
        *(s32*)(obj + 0x20) = 0x6C000;
        *(s16*)(obj + 0x8E) = 0x20;
        *(s16*)(obj + 0x90) = 0x20;
        *(s16*)(obj + 0x92) = 0x50;
        *(s16*)(obj + 0x42) = 0x7842;
        *(u8**)(obj + 0x3C) = p;
        func_8003D4C0(0x21, 2, 0, 0);
    } else {
        *(u8**)(obj + 0x68) = D_80076E6C;
        *(u8**)(obj + 0x50) = D_80076E68;
        *(s16*)(obj + 0x40) = 0x540;
        q = D_1F80001C.bytes;
        q += *(s32*)(q + 0x18);
        *(s32*)(obj + 0x20) = 0xA0000;
        *(s16*)(obj + 0x8E) = 0x40;
        *(s16*)(obj + 0x90) = 0x40;
        *(s16*)(obj + 0x92) = 0x70;
        *(s16*)(obj + 0x42) = 0x7844;
        *(u8**)(obj + 0x3C) = q;
    }
    *(s16*)(obj + 0x8C) = *(s16*)(obj + 0xA);
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    func_800171E8(obj, 0);
    obj[4]++;
}
