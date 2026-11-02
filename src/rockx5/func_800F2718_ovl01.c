#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0A0[];
extern u8 D_800750C0[];
extern u8 D_800FC864_ovl01[];
extern u8 D_800FC868_ovl01[];
extern u8 D_800FC86C_ovl01[];
extern u8 D_800FC914_ovl01[];

void func_800F2718_ovl01(u8* obj) {
    s32 x;

    obj[0x5C] = 0x10;
    obj[0x60] = 5;
    x = *(s32*)(obj + 8);
    obj[0x14] = D_8009A0A0[0x14];
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (*(s32*)(D_8009A0A0 + 8) < x) {
        obj[0x15] = 0;
    } else {
        obj[0x15] = 0x40;
    }
    *(u8**)(obj + 0x30) = D_800FC914_ovl01;
    obj[0x16] = 4;
    obj[0x70] = 0;
    *(u8**)(obj + 0x68) = D_800FC86C_ovl01;
    *(u8**)(obj + 0x54) = D_800FC868_ovl01;
    *(u8**)(obj + 0x50) = D_800FC864_ovl01;
    obj[0x67] = 0;
    *(u8**)(obj + 0x58) = D_800750C0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    D_1F80004C.bytes[0x80] = 0;
    D_1F80004C.bytes[0x81] = 0;
    D_1F80004C.bytes[0x82] = 0;
    D_1F80004C.bytes[0x83] = 0;
    *(s32*)(D_1F80004C.bytes + 0x84) = 0;
    obj[5] = 2;
    obj[6] = 0;
    obj[4]++;
    func_800171E8(obj, 0);
}
