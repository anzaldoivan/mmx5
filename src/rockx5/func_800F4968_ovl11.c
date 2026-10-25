#include "types.h"

extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];

void func_800F4968_ovl11(u8* arg0) {
    u8* p = D_8009A0A0;
    u8* r;

    if (*(s16*)(p + 0xA) >= 0xE21) {
        u8* q = D_8009A1F8;
        arg0[0x83] = 0x1E;
        arg0[0x87] = 1;
        *(s16*)(q + 0x26) = 0xDC0;
        *(s16*)(q + 0x28) = 0x4B0;
        *(s16*)(q + 0x2A) = 0x4B0;
        arg0[5] = 7;
        func_8001296C(6);
        func_80016490(5, 0x1A, arg0);
    }
    r = D_8009A1F8;
    if (*(s16*)(p + 0xE) < *(s16*)(r + 0xE) - 4) {
        *(s16*)(p + 0xE) = *(s16*)(r + 0xE) - 4;
    }
}
