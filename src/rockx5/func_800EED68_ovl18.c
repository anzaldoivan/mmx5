#include "types.h"

extern s32 func_80028B18(s32, s32, s32, void*);
extern s32 func_8003D29C(s32, s32);
extern s32 func_8003D2C4(void);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_800F6CCC_ovl18[];
extern void* D_800F6CF4_ovl18[];

void func_800EED68_ovl18(u8* arg0) {
    u8* p = D_8009A0A0;
    u8* b;
    u8* q;
    u8* r;

    if (p[0xF7] == 0) {
        ((void (*)(u8*))D_800F6CF4_ovl18[*(s8*)(arg0 + 5)])(arg0);
        *(u16*)(arg0 + 0x14) += 1;
    }
    if (*(s16*)(arg0 + 0x1A) == 0) {
        b = D_8009A1F8;
        if (*(s16*)(b + 0x26) == 0xBA0 && *(s16*)(b + 0x2A) == 0x5A0 &&
            *(s16*)(p + 0xE) >= 0x5C0) {
            func_80028B18(0, 0xD30, 0x590, D_800F6CCC_ovl18);
            *(s16*)(arg0 + 0x1A) = 1;
        }
    }
    switch (*(s8*)(arg0 + 0x1C)) {
    case 0:
        q = D_8009A0A0;
        if ((u16)(*(u16*)(q + 0xA) - 0xD30) < 0x40 &&
            (u16)(*(u16*)(q + 0xE) - 0x510) < 0x80) {
            func_8003D29C(0x14, q[0x15]);
            *(s8*)(arg0 + 0x1C) = 1;
        }
        break;
    case 1:
        r = D_8009A0A0;
        if (*(s8*)(r + 5) == 0x14) {
            func_8003D2C4();
            *(s8*)(arg0 + 0x1C) = 2;
        }
        break;
    }
}
