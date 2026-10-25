#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F188C_ovl05(u8* obj) {
    obj[0x91] = 1;
    switch (*(s8*)(obj + 2)) {
    case 0:
    case 3:
        obj[5] = 3;
        func_800171E8(obj, 0);
        break;
    case 1:
    case 4:
        obj[5] = 4;
        func_800171E8(obj, 3);
        break;
    case 2:
    case 5:
        obj[5] = 5;
        func_800171E8(obj, 6);
        break;
    }
    obj[6] = 0;
    obj[0x5C] = 12;
    obj[0x90] = 0;
    *(s16*)(obj + 0x8A) = 0;
}
