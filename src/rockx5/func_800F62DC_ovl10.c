#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_800317B8(u8* a0);
extern u8* func_8002D1A4();
extern u8 D_8009A0A0[];

static inline u8 func_800F62DC_ovl10_check(u8* obj) {
    u8* d = D_8009A0A0;

    if (((s8*)d)[0xCA] == 0) {
        if (func_800317B8(obj) == 0) {
            return 0;
        }
        if (((s8*)d)[0xCA] != 0) {
            return 1;
        }
    }
    return 0;
}

void func_800F62DC_ovl10(u8* obj) {
    u8* parent = *(u8**)(obj + 0x7C);
    u8* child;
    u8* d;

    switch (parent[0x47]) {
    case 0x9E:
    case 0xA2:
        func_80016490(2, 0x2A, obj);
        obj[0x8C] = 8;
        obj[0x8D] = 2;
        obj[0x8E] = 0x30;
        obj[0x8F] = 4;
        func_800171E8(obj, 0x18);
        break;
    case 0xA1:
    case 0xA3:
        ((s8*)obj)[0x8C] = -0x10;
        obj[0x8D] = 2;
        obj[0x8E] = 0x50;
        obj[0x8F] = 4;
        func_800171E8(obj, 0x18);
        break;
    case 0x76:
    case 0x7F:
        ((s8*)obj)[0x8C] = -0x60;
        obj[0x8D] = 2;
        ((s8*)obj)[0x8E] = -0x60;
        obj[0x8F] = 4;
        func_800171E8(obj, 4);
        break;
    default:
        obj[3] = 0;
        obj[4] = 2;
        return;
    }
    *(u8**)(obj + 0x50) = obj + 0x8C;

    if (func_800F62DC_ovl10_check(obj) == 0) {
        return;
    }
    parent[7] = 2;
    obj[5] = 1;
    child = func_8002D1A4();
    if (child != 0) {
        child[0] = 0x41;
        child[1] = 0x27;
        child[2] = 5;
        child[4] = 0xE;
        *(s32*)(child + 0x24) = 0;
        child[0x15] = D_8009A0A0[0x15];
        *(s32*)(child + 8) = *(s32*)(D_8009A0A0 + 8);
        *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
        *(u16*)(child + 0x40) = *(u16*)(parent + 0x40);
        *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        *(s32*)(child + 0x30) = *(s32*)(parent + 0x30);
        *(s32*)(child + 0x3C) = *(s32*)(parent + 0x3C);
        child[0x14] = obj[0x14];
        *(u8**)(child + 0x7C) = obj;
    }
    d = D_8009A0A0;
    *(s32*)(d + 0xC) = *(s32*)(child + 0xC);
}
