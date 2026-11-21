#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"

#define func_800FCA50_ovl39 func_800FCC64_ovl39
#include "shared/func_800FCA50_ovl39.c"
#undef func_800FCA50_ovl39

void func_800FCCC0_ovl39(u8* o) {
    u8* c;

    if (--*(s16*)(o + 0x7C) == 0) {
        if (*(s16*)(o + 0x7E) != 5) {
            c = func_8002D1A4();
            if (c != 0) {
                c[0] = 0x61;
                c[1] = 0x28;
                c[2] = o[0x7E] + 6;
                *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
                *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
                *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
                *(u16*)(c + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
                c[0x15] = o[0x15];
                *(u8**)(c + 0x7C) = o;
            }
            *(s16*)(o + 0x7C) = 0x28;
            *(s16*)(o + 0x7E) = *(s16*)(o + 0x7E) + 1;
            return;
        }
        o[6]++;
    }
}

extern u8 D_800FEB34_ovl39[];

void func_800FCDA4_ovl39(u8* arg0) {
    u8 c;

    if (D_1F80004C.bytes[0x8B] == 1) {
        D_1F80004C.bytes[0x8B] = 0;
        c = ++D_1F80004C.bytes[0x87];
        c = D_800FEB34_ovl39[c + D_1F80004C.bytes[0x86] * 2];
        arg0[6] = 0;
        arg0[5] = c;
    }
}

#define D_800EEC60_ovl00 func_800FCE14_ovl39
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
