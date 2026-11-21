#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

extern s32 func_8002B5B4(s32);
extern void func_800F47CC_ovl01(u8* obj, s32 arg1);
extern u8 D_800FCBD0_ovl01[];
extern u8 D_800FC9A8_ovl01[];
extern u8 D_800FC9AC_ovl01[];
extern u8 D_800FC9B0_ovl01[];
extern u8 D_800FC9B4_ovl01[];
extern u8 D_800FC9B8_ovl01[];
extern u8 D_800FC9BC_ovl01[];
extern u8 D_800FC9C0_ovl01[];
extern u8 D_80075200[];
extern u8 D_800FCC1C_ovl01[][5][5];

void func_800F312C_ovl01(u8* obj) {
    u8* d = g_Player;

    obj[0x5C] = 0x1F;
    obj[0x60] = 5;
    obj[0x61] = 0;
    obj[0x14] = d[0x14];
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x30) = D_800FCBD0_ovl01;
    obj[0x70] = 0;

    switch (((s8*)obj)[2]) {
    case 0:
        *(u8**)(obj + 0x68) = D_800FC9B0_ovl01;
        *(u8**)(obj + 0x54) = D_800FC9A8_ovl01;
        *(u8**)(obj + 0x50) = D_800FC9AC_ovl01;
        {
            u8* e = g_Player;
            s32 v = *(s32*)(e + 8);
            obj[0x16] = 7;
            *(u8**)(obj + 0x58) = D_80075200;
            obj[0x15] = (v >= *(s32*)(obj + 8)) << 6;
        }
        set_animation(obj, 0);
        D_1F80004C.bytes[0x84] = random_byte() & 3;
        D_1F80004C.bytes[0x85] = 0;
        D_1F80004C.bytes[0x87] = 1;
        D_1F80004C.bytes[0x86] = 0;
        D_1F80004C.bytes[0x88] = 1;
        D_1F80004C.bytes[0x89] = 0;
        D_1F80004C.bytes[0x8A] = 0;
        obj[4] = 1;
        obj[5] = D_800FCC1C_ovl01[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        break;
    case 1:
        *(s16*)(obj + 0x42) =
            ((func_8002B5B4(((s8*)obj)[1]) * 4 + 0x1A) % 16) |
            (((func_8002B5B4(((s8*)obj)[1]) + 6) / 4 + 0x1E0) << 6);
        *(u8**)(obj + 0x68) = D_800FC9B0_ovl01;
        *(u8**)(obj + 0x54) = D_800FC9A8_ovl01;
        *(u8**)(obj + 0x50) = D_800FC9AC_ovl01;
        {
            u8* e = g_Player;
            s32 v = *(s32*)(e + 8);
            obj[0x16] = 7;
            *(u8**)(obj + 0x58) = D_80075200;
            obj[0x15] = (v >= *(s32*)(obj + 8)) << 6;
        }
        set_animation(obj, 4);
        D_1F80004C.bytes[0x84] = random_byte() & 3;
        D_1F80004C.bytes[0x85] = 0;
        D_1F80004C.bytes[0x87] = 1;
        D_1F80004C.bytes[0x86] = 0;
        D_1F80004C.bytes[0x88] = 1;
        D_1F80004C.bytes[0x89] = 0;
        D_1F80004C.bytes[0x8A] = 0;
        obj[4] = 1;
        obj[5] = D_800FCC1C_ovl01[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        break;
    case 2:
        *(s16*)(obj + 0x42) =
            ((func_8002B5B4(((s8*)obj)[1]) * 4 + 0x19) % 16) |
            (((func_8002B5B4(((s8*)obj)[1]) + 6) / 4 + 0x1E0) << 6);
        *(u8**)(obj + 0x68) = D_800FC9B0_ovl01;
        *(u8**)(obj + 0x54) = D_800FC9A8_ovl01;
        *(u8**)(obj + 0x50) = D_800FC9AC_ovl01;
        {
            u8* e = g_Player;
            s32 v = *(s32*)(e + 8);
            obj[0x16] = 7;
            *(u8**)(obj + 0x58) = D_80075200;
            obj[0x15] = (v >= *(s32*)(obj + 8)) << 6;
        }
        set_animation(obj, 0);
        D_1F80004C.bytes[0x84] = random_byte() & 3;
        D_1F80004C.bytes[0x85] = 0;
        D_1F80004C.bytes[0x87] = 1;
        D_1F80004C.bytes[0x86] = 0;
        D_1F80004C.bytes[0x88] = 1;
        D_1F80004C.bytes[0x89] = 0;
        D_1F80004C.bytes[0x8A] = 0;
        obj[4] = 1;
        obj[5] = D_800FCC1C_ovl01[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        func_800F47CC_ovl01(obj, 0x10);
        break;
    case 3:
        *(s16*)(obj + 0x42) =
            ((func_8002B5B4(((s8*)obj)[1]) * 4 + 0x1A) % 16) |
            (((func_8002B5B4(((s8*)obj)[1]) + 6) / 4 + 0x1E0) << 6);
        *(u8**)(obj + 0x68) = D_800FC9B0_ovl01;
        *(u8**)(obj + 0x54) = D_800FC9A8_ovl01;
        *(u8**)(obj + 0x50) = D_800FC9AC_ovl01;
        {
            u8* e = g_Player;
            s32 v = *(s32*)(e + 8);
            obj[0x16] = 7;
            *(u8**)(obj + 0x58) = D_80075200;
            obj[0x15] = (v >= *(s32*)(obj + 8)) << 6;
        }
        set_animation(obj, 0);
        D_1F80004C.bytes[0x84] = random_byte() & 3;
        D_1F80004C.bytes[0x85] = 0;
        D_1F80004C.bytes[0x87] = 1;
        D_1F80004C.bytes[0x86] = 0;
        D_1F80004C.bytes[0x88] = 1;
        D_1F80004C.bytes[0x89] = 0;
        D_1F80004C.bytes[0x8A] = 0;
        obj[4] = 1;
        obj[5] = D_800FCC1C_ovl01[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        func_800F47CC_ovl01(obj, 0x11);
        break;
    case 16:
        obj[0x5C] = 6;
        *(s32*)(obj + 0x68) = 0;
        *(u8**)(obj + 0x54) = D_800FC9B4_ovl01;
        *(u8**)(obj + 0x50) = D_800FC9B8_ovl01;
        obj[0x16] = 6;
        set_animation(obj, 5);
        D_1F80004C.bytes[0x85] = 1;
        *(u8**)(obj + 0x58) = D_80075200;
        obj[4] = 2;
        obj[5] = 2;
        obj[6] = 0;
        break;
    case 17:
        obj[0x5C] = 6;
        *(s32*)(obj + 0x68) = 0;
        *(u8**)(obj + 0x54) = D_800FC9BC_ovl01;
        *(u8**)(obj + 0x50) = D_800FC9C0_ovl01;
        obj[0x16] = 6;
        set_animation(obj, 8);
        D_1F80004C.bytes[0x85] = 1;
        *(u8**)(obj + 0x58) = D_80075200;
        obj[4] = 2;
        obj[5] = 2;
        obj[6] = 0;
        break;
    }
}

#define D_800FAA1C_ovl00 D_800FC9A8_ovl01
#define D_800FAA20_ovl00 D_800FC9AC_ovl01
#define D_800FAC8C_ovl00 D_800FCC18_ovl01
#define D_800FAD10_ovl00 D_800FCC9C_ovl01
#define func_800F1C8C_ovl00 func_800F36F0_ovl01
#define D_800FAD34_ovl00 D_800FCCC0_ovl01
#define func_800F2F40_ovl00 func_800F49A4_ovl01
#define func_800F1E5C_ovl00 func_800F38C0_ovl01
#define D_800FAC90_ovl00 D_800FCC1C_ovl01
#define func_800F2038_ovl00 func_800F3A9C_ovl01
#include "shared/func_800F1C8C_ovl00.c"
#undef func_800F1C8C_ovl00
#undef D_800FAA1C_ovl00
#undef D_800FAA20_ovl00
#undef D_800FAC8C_ovl00
#undef D_800FAD10_ovl00
#undef func_800F1E5C_ovl00
#undef D_800FAD34_ovl00
#undef func_800F2F40_ovl00
#undef func_800F2038_ovl00
#undef D_800FAC90_ovl00

#define D_800F4844_ovl05 D_800FCC80_ovl01

#define func_800EEA80_ovl05 func_800F3BA0_ovl01
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800F2178_ovl00 func_800F3BDC_ovl01
#include "shared/func_800F2178_ovl00.c"
#undef func_800F2178_ovl00

#define func_8002D720 func_8002D7A0

#define func_800F2178_ovl00 func_800F3C3C_ovl01
#include "shared/func_800F2178_ovl00.c"
#undef func_800F2178_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800F3C9C_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F2258_ovl00 func_800F3CBC_ovl01
#include "shared/func_800F2258_ovl00.c"
#undef func_800F2258_ovl00
