#include "types.h"

extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern void func_8002DED4(u8* obj);
extern void func_800F0924_ovl07(u8* obj);
extern void func_800EFF18_ovl07(u8* obj);

void func_800F04E8_ovl07(u8* obj) {
    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        *(s32*)(obj + 0x2C) = 0x5000;
    }
    obj[0x67] = 1;
    func_800EFCE4_ovl07(obj, 4);
    if ((*(s32*)(obj + 0x70) & 5) != 5) {
        func_8002DED4(obj);
        if (*(s32*)(obj + 0x24) < 0) {
            obj[5] = 4;
            obj[6] = 0;
        } else if (!(*(u16*)(obj + 0x8A) & 0x80)) {
            obj[5] = 4;
            obj[6] = 0;
            *(s32*)(obj + 0x24) = 0;
        }
    } else {
        obj[5] = 4;
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        if (obj[0x70] & 1) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
        }
    }
    func_800F0924_ovl07(obj);
    if (obj[0x7D] != 0) {
        *(s16*)(obj + 0x8E) = 1;
    }
    func_800EFF18_ovl07(obj);
}
