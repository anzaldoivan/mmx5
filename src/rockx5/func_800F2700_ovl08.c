#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern void func_800F28E8_ovl08(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void func_800F2700_ovl08(u8* a0) {
    s8 r;

    func_80017248(a0);
    r = func_80031DD0(a0);
    if (r == 5 || r == 14 || r == 36 || r < 0) {
        a0[3] = 1;
        *(u16*)(a0 + 0x42) &= 0x7FFF;
        func_800F28E8_ovl08(a0);
        func_800F28E8_ovl08(a0);
        func_800F28E8_ovl08(a0);
        func_800F28E8_ovl08(a0);
        *(s16*)(a0 + 0x7C) = 0x78;
        *(s16*)(a0 + 0x7E) = 8;
        a0[4] = 5;
    } else if (func_8002D938(a0, 0xA0, 0x60) == 1) {
        a0[4] = 7;
    }
}
