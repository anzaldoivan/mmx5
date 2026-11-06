#include "types.h"

extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];

void func_800F3DB8_ovl29(u8* obj) {
    s16 d;
    s32 st;
    u8* b;
    u8* b2;

    func_80017248(obj);
    st = *(s8*)(obj + 0x45);
    if (st == 1) {
        *(s32*)(obj + 0x24) = 0x40000;
        obj[0x67] = st;
        obj[0x45] = 0;
        *(s32*)(obj + 0x2C) = 0x1C00;
        st = obj[6];
        obj[6] = st + 1;
        b = D_8009A0A0;
        if (*(s16*)(obj + 0xA) > *(s16*)(b + 0xA)) {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = 0xFFFA0000;
        } else {
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = 0x60000;
        }
        b2 = D_8009A0A0;
        if (*(s16*)(obj + 0xA) - *(s16*)(b2 + 0xA) >= 0) {
            d = *(u16*)(obj + 0xA) - *(u16*)(b2 + 0xA);
        } else {
            d = *(u16*)(b2 + 0xA) - *(u16*)(obj + 0xA);
        }
        *(s32*)(obj + 0x20) = obj[0x15] != 0 ? 0x60000 : 0xFFFA0000;
        if (d < 0x30) {
            *(s32*)(obj + 0x28) = -0x8000;
        } else if (d < 0x60) {
            *(s32*)(obj + 0x28) = -0x4000;
        } else {
            *(s32*)(obj + 0x28) = -0x2000;
        }
    }
}
