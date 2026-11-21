#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

void func_801003AC_ovl04(u8* obj) {
    signed char r = func_80031DD0(obj);
    s32 st;

    if (r == 0x25 || r == 0x40) {
        if (*(signed char*)(obj + 2) == 0) {
            *(u16*)(obj + 0xE) += 0x10;
        }
        func_8004FD90(obj, 1, 0x3F, 0x1F);
        func_8004FD90(obj, 1, 0x3F, 0x1F);
        func_8004FD90(obj, 1, 0x3F, 0x1F);
        r = 0x78;
        st = 3;
        *(u16*)(obj + 0x7C) = r;
    } else {
        if (is_off_screen(obj, 0x40, 0x40) != 1) {
            return;
        }
        st = 4;
    }
    obj[4] = st;
}

#define D_800EEBA0_ovl00 func_80100470_ovl04
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_8009A244;
extern u8 D_80102F58_ovl04[];
extern u8 D_80102F60_ovl04[];

void func_80100490_ovl04(u8* obj) {
    if (!(*(u16*)(obj + 0x7C) & 7)) {
        ((s32(*)())func_8004FD90)(obj, 1, 0x3F, 0x1F);
    }
    if (*(s16*)(obj + 0x7C) == 0) {
        *(s32*)(obj + 0x20) = 0;
        ((s32(*)())func_8004FD90)(obj, 1, 0x3F, 0x1F);
        ((s32(*)())func_8004FD90)(obj, 1, 0x3F, 0x1F);
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

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_801005A4_ovl04
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
