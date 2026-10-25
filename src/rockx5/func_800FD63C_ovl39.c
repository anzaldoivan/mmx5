#include "types.h"

extern s32 D_8009A0A8;
extern void func_800171E8(u8* obj, s32 state);

void func_800FD63C_ovl39(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 7) != 0x11) {
        obj[0x84] = 0;
        obj[4] = 2;
    }
    if ((*(u8**)(obj + 0x7C))[0x89] == 2) {
        if (--*(s16*)(obj + 0x82) == 0) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = -0x18000;
            *(s32*)(obj + 0x8) = D_8009A0A8 + 0x140000;
            *(s16*)(obj + 0xE) = 0x710;
            func_800171E8(obj, 0xB);
            obj[6]++;
        }
    }
}
