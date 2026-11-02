#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800FA6B0_ovl28(u8* obj) {
    u8* p;
    u8 f;
    u16 e;

    p = *(u8**)(obj + 0x7C);
    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(p + 0x3C);
    obj[0x14] = 0;
    obj[0x16] = 1;
    f = p[0x15];
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    obj[0x15] = f;
    if (f == 0) {
        *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0x1E;
    } else {
        *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0x1E;
    }
    e = *(u16*)(*(u8**)(obj + 0x7C) + 0xE);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0xE) = e - 0xA;
    func_800171E8(obj, 0xD);
    obj[0x5C] = 0;
    obj[0x60] = 0;
    obj[0x5] = 0;
    obj[0x4]++;
}
