#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DED4(u8* obj);
extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern void func_800EFF18_ovl07(u8* obj);
extern void func_800F0924_ovl07(u8* obj);
extern u8 D_8009A0A0[];

void func_800EF560_ovl07(u8* obj) {
    s8 v;

    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        *(s32*)(obj + 0x2C) = 0x5000;
    }
    obj[0x67] = 1;
    func_800EFCE4_ovl07(obj, 4);
    if (obj[0x70] & 8) {
        obj[0x67] = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x24) = 0;
        if (obj[0x7D] != 0) {
            obj[5] = 5;
            obj[6] = 1;
            obj[0x99] = 0;
        } else {
            obj[5] = 1;
            obj[0x80] &= 0xFD;
            switch (obj[0x82]) {
            case 0:
                func_800171E8(obj, 5);
                v = 0x46;
                break;
            case 1:
                func_800171E8(obj, 4);
                v = 0x44;
                break;
            case 2:
                func_800171E8(obj, 3);
                v = 0x42;
                break;
            default:
                goto skip; // !FAKE: goto kept for the matching branch layout
            }
            D_8009A0A0[0xD8] = v;
            D_8009A0A0[6] = 0;
        skip:;
        }
    }
    func_8002DED4(obj);
    if (0x68000 - *(s32*)(obj + 0x24) < 0) {
        *(s32*)(obj + 0x24) = 0x68000;
    }
    func_800F0924_ovl07(obj);
    if (obj[0x7D] != 0) {
        *(s16*)(obj + 0x8E) = 1;
    }
    func_800EFF18_ovl07(obj);
}
