#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_80028B18(s32, s32, s32, void*);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_800FE624_ovl06[];
extern u8 D_8009A244;

void func_800F4938_ovl06(u8* obj) {
    if (*(s16*)(obj + 0x7C) == 0) {
        func_8002DED4(obj);
    } else {
        *(s16*)(obj + 0x7C) -= 1;
    }
    if (obj[0x70] & 1) {
        func_80028B18(0, 0xC80, 0xE0, D_800FE624_ovl06);
        D_8009A244 = 1;
        func_80016490(2, 0x1D, obj);
        func_8002A5C4(0x28, 4, 2);
        *(s16*)(obj + 0x7C) = 0x3C;
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        obj[6]++;
    }
}
