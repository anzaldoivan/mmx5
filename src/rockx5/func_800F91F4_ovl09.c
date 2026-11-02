#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F91F4_ovl09(u8* obj) {
    switch (*(s8*)(obj + 2)) {
    case 0:
        func_800171E8(obj, 5);
        obj[0x16] = 5;
        obj[3] = 1;
        obj[0x15] = 0;
        obj[4] = 1;
        obj[5] = 0;
        obj[6] = 0;
        break;
    case 1:
        if (obj[0x15] == 0) {
            *(u16*)(obj + 0xA) -= 0x48;
        } else {
            *(u16*)(obj + 0xA) += 0x48;
        }
        *(u16*)(obj + 0xE) -= 8;
        func_800171E8(obj, 3);
        obj[0x16] = 1;
        obj[3] = 0;
        *(u16*)(obj + 0x54) = 0x60;
        *(u16*)(obj + 0x56) = 0xA;
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
        break;
    case 2:
        func_800171E8(obj, 4);
        obj[0x16] = 1;
        obj[3] = 1;
        if (obj[0x15] == 0) {
            obj[0x15] = 0x40;
            *(u16*)(obj + 0xA) -= 0x18;
        } else {
            obj[0x15] = 0;
            *(u16*)(obj + 0xA) += 0x18;
        }
        *(u16*)(obj + 0x54) = 0x84;
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
        *(u16*)(obj + 0xE) -= 5;
        break;
    }
}
