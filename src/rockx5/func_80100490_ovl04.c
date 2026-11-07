#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8004FD90(u8*, s32, s32, s32);
extern u8 D_8009A244;
extern u8 D_80102F58_ovl04[];
extern u8 D_80102F60_ovl04[];

void func_80100490_ovl04(u8* obj) {
    if (!(*(u16*)(obj + 0x7C) & 7)) {
        func_8004FD90(obj, 1, 0x3F, 0x1F);
    }
    if (*(s16*)(obj + 0x7C) == 0) {
        *(s32*)(obj + 0x20) = 0;
        func_8004FD90(obj, 1, 0x3F, 0x1F);
        func_8004FD90(obj, 1, 0x3F, 0x1F);
        if (*(s8*)(obj + 2) == 0) {
            *(u16*)(obj + 0xE) -= 0x10;
        }
        func_8004FD24(obj);
        func_8004D4F4(4, D_80102F58_ovl04, obj);
        if (*(s8*)(obj + 2) == 0) {
            func_80028B18(0, 0xEE0, 0x2C0, D_80102F60_ovl04);
        } else {
            func_80028B18(0, 0xE60, 0x230, D_80102F60_ovl04);
        }
        D_8009A244 = 1;
        obj[4] = 2;
        return;
    }
    *(u16*)(obj + 0x7C) -= 1;
}
