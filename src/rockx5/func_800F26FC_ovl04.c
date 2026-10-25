#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F26FC_ovl04(u8* obj) {
    D_1F80004C.bytes[0x84] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    switch (((s8*)obj)[2]) {
    case 0:
        func_800171E8(obj, 0);
        obj[6] = 1;
        break;
    case 1:
        func_800171E8(obj, 1);
        obj[6] = 2;
        break;
    case 2:
    case 3:
        func_800171E8(obj, 1);
        obj[6] = 3;
        break;
    }
    *(s16*)(obj + 0x7C) = 0xB4;
}
