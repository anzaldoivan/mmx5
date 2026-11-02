#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_80074EE0[];
extern u8 D_8009A0B4;
extern u8 D_801010E4_ovl07[];
extern u8 D_801010E8_ovl07[];
extern u8 D_801010EC_ovl07[];
extern u8 D_801010F0_ovl07[];
extern u8 D_80101114_ovl07[];

void func_800F332C_ovl07(u8* obj) {
    obj[0x5C] = 0;
    obj[0x60] = 4;
    obj[0x61] = 0;
    *(u8**)(obj + 0x58) = D_80074EE0;
    obj[0x14] = D_8009A0B4;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(u16*)(D_1F80004C.bytes + 0x80) = *(u16*)(obj + 0xA);
    *(u16*)(D_1F80004C.bytes + 0x82) = *(u16*)(obj + 0xE);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x30) = D_80101114_ovl07;
    obj[0x16] = 1;
    *(s32*)(obj + 0x68) = 0;
    obj[0x15] = 0;
    D_1F80004C.bytes[0x84] = 0;
    if (((s8*)obj)[2] == 0) {
        func_800171E8(obj, 0);
        *(u8**)(obj + 0x54) = D_801010F0_ovl07;
        *(u8**)(obj + 0x50) = D_801010EC_ovl07;
        obj[5] = 4;
        *(s32*)(obj + 0x20) = -0x8000;
    } else {
        func_800171E8(obj, 1);
        *(u8**)(obj + 0x54) = D_801010E8_ovl07;
        *(u8**)(obj + 0x50) = D_801010E4_ovl07;
        obj[5] = 2;
        *(s32*)(obj + 0x24) = 0x8000;
    }
    obj[6] = 0;
    obj[4]++;
}
