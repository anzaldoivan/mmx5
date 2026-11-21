#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern s32 func_8002B5B4(s32);
extern u32* D_80098118;

void func_800EF504_ovl01(u8* arg0) {
    s32 a;
    s32 b;

    *(s16*)(arg0 + 0x40) = D_80098118[func_8002B5B4(0x89)] >> 7;
    a = func_8002B5B4(0x89) *
        2; // !FAKE: split scale keeps move s0 in the delay slot (C0314)
    b = func_8002B5B4(0x89);
    *(s16*)(arg0 + 0x42) = ((a * 2 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    a = func_8002B5B4(0x89);
    *(s32*)(arg0 + 0x3C) = (s32)D_1F800020.u32s + D_1F800020.u32s[a];
    ((s8*)arg0)[0x14] = -1;
    arg0[0x16] = 0;
    *(s16*)(arg0 + 0xA) = 0x1C0;
    if (((s8*)arg0)[2] == 0) {
        arg0[0x47] = 0;
    } else {
        arg0[0x47] = 1;
    }
    arg0[4]++;
}

extern u8 D_8009A197;
extern u8 D_8009A1F8[];

void func_800EF604_ovl01(u8* obj) {
    u8* p;

    if (D_8009A197 != 0) {
        u8* q = D_8009A1F8;
        s32 d = *(s32*)(q + 8) - *(s32*)(q + 0x14);
        d += d / 4;
        *(s32*)(obj + 8) -= d;
    } else {
        *(s16*)(obj + 0xA) -= 0xC;
    }
    p = D_8009A1F8;
    *(s16*)(obj + 0xE) = 0x200 - *(u16*)(p + 0x62);
    ((s32(*)())func_8002D9EC)(obj, 0x100, 0x100);
    if (*(s8*)(obj + 3) == 0) {
        obj[4]++;
    }
}

#define D_800EEBA0_ovl00 func_800EF6C0_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
