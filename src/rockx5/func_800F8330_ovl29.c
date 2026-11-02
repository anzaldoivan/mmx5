#include "types.h"

extern s32 func_800171E8(u8* obj, s32 state);
extern void func_8002D89C(u8* obj);

void func_800F8330_ovl29(u8* obj) {
    u8* p = *(u8**)(obj + 0x50);

    *(s32*)(obj + 0x8) = *(s32*)(p + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(p + 0x3C);
    obj[0x14] = p[0x14];
    obj[0x15] = 0;

    switch (*(s8*)(obj + 2)) {
    case 5:
        func_800171E8(obj, 0x15);
        obj[0x16] = 4;
        obj[4] = 4;
        break;
    case 4:
        func_800171E8(obj, 0xE);
        obj[0x16] = 4;
        obj[4] = 4;
        break;
    case 3:
        func_800171E8(obj, 0x17);
        obj[0x16] = 4;
        obj[4] = 1;
        break;
    case 2:
        func_800171E8(obj, 0x18);
        obj[0x16] = 7;
        obj[4] = 1;
        break;
    case 0: // !FAKE: explicit to keep the jump table
    case 1:
    default:
        func_800171E8(obj, 0x19);
        obj[0x16] = 4;
        obj[4] = 3;
        break;
    }
    func_8002D89C(obj);
}
