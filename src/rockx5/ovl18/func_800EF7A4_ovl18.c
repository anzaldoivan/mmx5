#include "types.h"
#include "mmx5/globals.h"

extern s32 func_800EF57C_ovl18(u8* obj, u8* base);

void func_800EF7A4_ovl18(u8* obj) {
    u8* p = g_Player;

    if (func_800EF57C_ovl18(obj, p) != 0) {
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE) - (*(u8**)(p + 0x68))[3];
        ((s32(*)())func_8003D29C)(0x14, p[0x15]);
        obj[6]++;
    }
}
