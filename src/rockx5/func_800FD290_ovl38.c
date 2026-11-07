#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800FD290_ovl38(u8* obj) {
    s8 state;

    state = obj[2];
    obj[3] = 0;
    obj[0x16] = 4;
    switch (state) {
    case 0:
        obj[0x16] = 6;
        func_800171E8(obj, 2);
        *(s32*)(obj + 0x20) = 0x18000;
        obj[3] = 1;
        *(s32*)(obj + 0x24) = 0x28000;
        obj[0x15] = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        *(s32*)(obj + 0x28) = 0;
        obj[5] = 0;
        *(s16*)(obj + 0x54) = 0;
        ((s16*)obj)[5] -= 0x10;
        ((s16*)obj)[7] -= 0x20;
        break;
    case 1:
        func_800171E8(obj, 0x12);
        obj[5] = state;
        *(s16*)(obj + 0x54) = 0x78;
        break;
    case 2:
        func_800171E8(obj, 0x10);
        obj[5] = state;
        break;
    }
    obj[6] = 0;
    obj[4]++;
}
