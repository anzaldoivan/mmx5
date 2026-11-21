#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

extern s32 func_8002B5B4(s32);
extern void func_800F2D68_ovl00(u8* obj, s32 arg1);
extern u8 D_800FAC44_ovl00[];
extern u8 D_800FAA1C_ovl00[];
extern u8 D_800FAA20_ovl00[];
extern u8 D_800FAA24_ovl00[];
extern u8 D_800FAA28_ovl00[];
extern u8 D_800FAA2C_ovl00[];
extern u8 D_800FAA30_ovl00[];
extern u8 D_800FAA34_ovl00[];
extern u8 D_80075200[];
extern u8 D_800FAC90_ovl00[][5][5];

void func_800F16C8_ovl00(u8* obj) {
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
    *(u8**)(obj + 0x30) = D_800FAC44_ovl00;
    obj[0x70] = 0;

    switch (((s8*)obj)[2]) {
    case 0:
        *(u8**)(obj + 0x68) = D_800FAA24_ovl00;
        *(u8**)(obj + 0x54) = D_800FAA1C_ovl00;
        *(u8**)(obj + 0x50) = D_800FAA20_ovl00;
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
        obj[5] = D_800FAC90_ovl00[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        break;
    case 1:
        *(s16*)(obj + 0x42) =
            ((func_8002B5B4(((s8*)obj)[1]) * 4 + 0x1A) % 16) |
            (((func_8002B5B4(((s8*)obj)[1]) + 6) / 4 + 0x1E0) << 6);
        *(u8**)(obj + 0x68) = D_800FAA24_ovl00;
        *(u8**)(obj + 0x54) = D_800FAA1C_ovl00;
        *(u8**)(obj + 0x50) = D_800FAA20_ovl00;
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
        obj[5] = D_800FAC90_ovl00[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        break;
    case 2:
        *(s16*)(obj + 0x42) =
            ((func_8002B5B4(((s8*)obj)[1]) * 4 + 0x19) % 16) |
            (((func_8002B5B4(((s8*)obj)[1]) + 6) / 4 + 0x1E0) << 6);
        *(u8**)(obj + 0x68) = D_800FAA24_ovl00;
        *(u8**)(obj + 0x54) = D_800FAA1C_ovl00;
        *(u8**)(obj + 0x50) = D_800FAA20_ovl00;
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
        obj[5] = D_800FAC90_ovl00[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        func_800F2D68_ovl00(obj, 0x10);
        break;
    case 3:
        *(s16*)(obj + 0x42) =
            ((func_8002B5B4(((s8*)obj)[1]) * 4 + 0x1A) % 16) |
            (((func_8002B5B4(((s8*)obj)[1]) + 6) / 4 + 0x1E0) << 6);
        *(u8**)(obj + 0x68) = D_800FAA24_ovl00;
        *(u8**)(obj + 0x54) = D_800FAA1C_ovl00;
        *(u8**)(obj + 0x50) = D_800FAA20_ovl00;
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
        obj[5] = D_800FAC90_ovl00[((s8*)obj)[2]][D_1F80004C.bytes[0x84]]
                                 [D_1F80004C.bytes[0x85]];
        obj[6] = 0;
        func_800F2D68_ovl00(obj, 0x11);
        break;
    case 16:
        obj[0x5C] = 6;
        *(s32*)(obj + 0x68) = 0;
        *(u8**)(obj + 0x54) = D_800FAA28_ovl00;
        *(u8**)(obj + 0x50) = D_800FAA2C_ovl00;
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
        *(u8**)(obj + 0x54) = D_800FAA30_ovl00;
        *(u8**)(obj + 0x50) = D_800FAA34_ovl00;
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

#include "shared/func_800F1C8C_ovl00.c"

#define D_800F4844_ovl05 D_800FACF4_ovl00

#define func_800EEA80_ovl05 func_800F213C_ovl00
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800F2178_ovl00.c"

#define func_8002D720 func_8002D7A0

#define func_800F2178_ovl00 func_800F21D8_ovl00
#include "shared/func_800F2178_ovl00.c"
#undef func_800F2178_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800F2238_ovl00
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F2258_ovl00.c"
