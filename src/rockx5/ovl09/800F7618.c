#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_8002CF70(void);
extern s32 func_8003A190(u8*);

void func_800F7618_ovl09(u8* a0) {
    u8* p;

    if (a0[0x72] & 8) {
        p = g_Player;
        *(s16*)(p + 0xA) = *(s16*)(a0 + 0xA);
        *(s16*)(p + 0xE) = *(s16*)(a0 + 0xE) - (*(u8**)(a0 + 0x68))[3] -
                           (*(u8**)(p + 0x68))[3];
        func_8003D29C(0x14, p[0x15]);
        func_8002CF70();
        func_8003A190(p);
        a0[5] = 1;
    }
}

extern s8 D_8009A170;

void func_800F76A4_ovl09(u8* obj) {
    if (D_8009A170 < 0) {
        *(s16*)(obj + 0x84) = 0;
        D_8009A1F8.h[0x12] = D_8009A1F8.h[0x13] = D_8009A1F8.h[5];
        set_animation(obj, 1);
        obj[5] = 2;
    }
}

#define D_8007BD4C D_800FB2B4_ovl09

#define func_800532E0 func_800F76F8_ovl09
#include "shared/func_800532E0.c"
#undef func_800532E0
