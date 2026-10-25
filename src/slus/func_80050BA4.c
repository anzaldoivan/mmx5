#include "types.h"
#include "addr.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_800171E8(u8*, s32);
extern s32 func_8002DF78(void);
extern void func_8002D89C(u8*);
extern s32 D_8007B804;
extern u8 D_8009A0B4;

void func_80050BA4(u8* arg0) {
    u8* s;

    FX(arg0, u8, 0x3) = 1;
    FX(arg0, s32, 0x38) = 0;
    s = D_1F80001C.bytes;
    FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x8);
    FX(arg0, void*, 0x30) = &D_8007B804;
    FX(arg0, u8, 0x14) = D_8009A0B4;
    FX(arg0, s16, 0x40) = 0;
    if (FX(arg0, signed char, 0x5C) != 2) {
        FX(arg0, s16, 0x42) = 0x7805;
    } else {
        FX(arg0, s16, 0x42) = 0x7806;
    }
    if (FX(arg0, signed char, 0x7) == 0) {
        FX(arg0, u8, 0x16) = 1;
    }
    func_800171E8(arg0, FX(arg0, signed char, 0x5C));
    FX(arg0, u8, 0x4)++;
    FX(arg0, signed char, 0x7) = func_8002DF78() & 1;
    func_8002D89C(arg0);
}
