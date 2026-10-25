#include "types.h"

extern u8 D_8009A0A0[];
extern s32 func_800EF57C_ovl18(u8* obj, u8* base);
extern s32 func_8003D29C(s32, s32);

void func_800EF7A4_ovl18(u8* obj) {
    u8* p = D_8009A0A0;

    if (func_800EF57C_ovl18(obj, p) != 0) {
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE) - (*(u8**)(p + 0x68))[3];
        func_8003D29C(0x14, p[0x15]);
        obj[6]++;
    }
}
