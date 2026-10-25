#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);

void func_800FA954_ovl28(u8* obj) {
    u8* parent = *(u8**)(obj + 0x7C);

    *(u16*)(obj + 0x40) = *(u16*)(parent + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(parent + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(parent + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(parent + 0x3C);
    obj[0x14] = 0;
    obj[0x16] = 1;
    obj[0x15] = parent[0x15];
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    func_800171E8(obj, 0x11);
    obj[0x5C] = 0;
    obj[0x60] = 0;
    func_80016490(2, 0x8D, obj);
    obj[0x4]++;
    obj[0x5] = 0;
}
