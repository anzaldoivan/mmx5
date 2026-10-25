#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s16 D_8009A0AA;

void func_800F9468_ovl28(u8* obj) {
    if (((s8*)obj)[2] == 0) {
        func_800171E8(obj, 3);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        *(s16*)(obj + 0x7C) = 0;
        obj[6] = 1;
    } else {
        func_800171E8(obj, 3);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[7] = 0;
        obj[6] = 4;
    }
}
