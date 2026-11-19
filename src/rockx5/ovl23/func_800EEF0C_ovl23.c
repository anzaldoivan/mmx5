#include "types.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

extern void func_8002C1C8(void);

void func_800EEF0C_ovl23(u8* arg0) {
    u16 n = *(u16*)(arg0 + 4);

    if (*(s16*)(arg0 + 4) != 0) {
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        *(u16*)(arg0 + 4) = n - 1;
    } else {
        arg0[1]++;
        func_8002C1C8();
    }
}
