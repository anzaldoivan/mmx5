#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern u8 D_80074DA0[];
extern u8 D_800FE97C_ovl06[];
extern u8 D_800FE980_ovl06[];
extern u8 D_800FE984_ovl06[];
extern u8 D_800FE988_ovl06[];

void func_800F625C_ovl06(u8* obj) {
    obj[4] = 1;
    obj[0x16] = 5;
    obj[0x60] = 4;
    obj[0x5C] = 2;
    *(u8**)(obj + 0x58) = D_80074DA0;
    obj[0x8C] = 7;
    *(u8**)(obj + 0x68) = D_800FE97C_ovl06;
    *(u8**)(obj + 0x54) = D_800FE984_ovl06;
    *(u8**)(obj + 0x50) = D_800FE980_ovl06;
    obj[0x67] = 0;
    obj[0x8E] = 0;
    obj[5] = 0;
    obj[0x15] = 0x40;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 0x30;
    *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) << 5;
    func_800171E8(obj, 4);
    if (*(s8*)(obj + 2) != 0) {
        *(u8**)(obj + 0x54) = D_800FE988_ovl06;
        *(u8**)(obj + 0x50) = D_800FE988_ovl06;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
    } else {
        func_80016490(2, 0x1C, obj);
    }
}
