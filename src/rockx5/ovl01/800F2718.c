#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800750C0[];
extern u8 D_800FC864_ovl01[];
extern u8 D_800FC868_ovl01[];
extern u8 D_800FC86C_ovl01[];
extern u8 D_800FC914_ovl01[];

void func_800F2718_ovl01(u8* obj) {
    s32 x;

    obj[0x5C] = 0x10;
    obj[0x60] = 5;
    x = *(s32*)(obj + 8);
    obj[0x14] = g_Player[0x14];
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (*(s32*)(g_Player + 8) < x) {
        obj[0x15] = 0;
    } else {
        obj[0x15] = 0x40;
    }
    *(u8**)(obj + 0x30) = D_800FC914_ovl01;
    obj[0x16] = 4;
    obj[0x70] = 0;
    *(u8**)(obj + 0x68) = D_800FC86C_ovl01;
    *(u8**)(obj + 0x54) = D_800FC868_ovl01;
    *(u8**)(obj + 0x50) = D_800FC864_ovl01;
    obj[0x67] = 0;
    *(u8**)(obj + 0x58) = D_800750C0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    D_1F80004C.bytes[0x80] = 0;
    D_1F80004C.bytes[0x81] = 0;
    D_1F80004C.bytes[0x82] = 0;
    D_1F80004C.bytes[0x83] = 0;
    *(s32*)(D_1F80004C.bytes + 0x84) = 0;
    obj[5] = 2;
    obj[6] = 0;
    obj[4]++;
    set_animation(obj, 0);
}

#define D_800EEBA0_ovl00 func_800F2840_ovl01
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F2860_ovl01
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F2688_ovl02 func_800F2880_ovl01
#include "shared/func_800F2688_ovl02.c"
#undef func_800F2688_ovl02
