#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void func_800F28E8_ovl08(u8* a0);

void func_800F2700_ovl08(u8* a0) {
    s8 r;

    animate_object(a0);
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
    } else if (is_off_screen(a0, 0xA0, 0x60) == 1) {
        a0[4] = 7;
    }
}
