#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0B4;

void func_800FBEE0_ovl39(u8* obj) {
    obj[0x14] = D_8009A0B4;
    switch (((s8*)obj)[2]) {
    case 0:
        obj[0x16] = 1;
        obj[3] = 1;
        obj[6] = 0;
        func_800171E8(obj, 10);
        break;
    case 1:
        obj[0x16] = 5;
        obj[3] = 0;
        obj[6] = 1;
        func_800171E8(obj, 1);
        obj[0x5C] = 0;
        break;
    case 2:
        obj[0x16] = 1;
        func_800171E8(obj, 7);
        obj[3] = 1;
        obj[6] = 2;
        break;
    case 3:
    case 4:
    case 5:
        obj[0x16] = 1;
        func_800171E8(obj, 13);
        obj[3] = 1;
        obj[6] = 3;
        break;
    case 6:
        obj[0x16] = 1;
        obj[3] = 1;
        func_800171E8(obj, 0x12);
        obj[0x5C] = 60;
        obj[6] = 4;
        break;
    }
    obj[4] = 1;
    obj[5] = 2;
}
