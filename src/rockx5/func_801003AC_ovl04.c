#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8004FD90(u8*, s32, s32, s32);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

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
        if (func_8002D938(obj, 0x40, 0x40) != 1) {
            return;
        }
        st = 4;
    }
    obj[4] = st;
}
