#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern u8* func_8002D144(void);
extern u8* func_8002D1A4();
extern signed char D_8009A0A5;
extern u8 D_8009A23F;

void func_800F8D08_ovl28(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        D_8009A23F = 2;
        func_8003D29C(0x1D, 0x40);
        a->unk7C = 0x28;
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(s16*)(p + 0xA) = a->unkA;
            *(s16*)(p + 0xE) = a->unkE;
            *(u8**)((u8*)a + 0x80) = p;
        }
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 8;
            *(Obj3DD4**)(p + 0x7C) = a;
        }
        a->unk6++;
    }
}
