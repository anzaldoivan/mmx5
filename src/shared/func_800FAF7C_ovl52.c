#include "types.h"
#include "mmx5/globals.h"

extern void func_8002C1C8(void);

void func_800FAF7C_ovl52(u8* arg0) {
    u16 t = --D_800D50DE;

    D_8009A42E -= 0x20;
    D_80093E68 -= 0x400;
    if (t == 1) {
        func_8002C1C8();
        *(u16*)(arg0 + 4) = 0;
        func_8002385C(0x4E, 0xFF, 0);
        arg0[1]++;
    }
}
