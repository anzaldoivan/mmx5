#include "types.h"

extern s8 D_800D1C28[];
extern void func_80016D54(s32, s32);
extern void func_8001296C(s32);
extern s32 func_80016490(s32, s32, void*);

void func_800F48F8_ovl11(u8* a0) {
    if (D_800D1C28[1] < 3) {
        func_80016D54(5, 0x1C);
    }
    if (a0[0x72] & 0xB) {
        func_8001296C(6);
        func_80016490(5, 0x1C, a0);
        a0[5] = 6;
    }
}
