#include "types.h"

extern s16 D_8009A0AA;
extern s16 D_8009A1F8[];
extern void func_8003D2C4(void);

void func_800EFAC8_ovl04(u8* a0) {
    if (D_8009A0AA - D_8009A1F8[5] <= (u16)D_8009A1F8[0x18]) {
        D_8009A1F8[0xE] = 0xB40;
        D_8009A1F8[0x12] = 0xB40;
        a0[5] = 3;
        a0[6] = 0;
        func_8003D2C4();
    } else {
        D_8009A1F8[5] += 2;
        D_8009A1F8[0xE] += 2;
        D_8009A1F8[0x12] += 2;
    }
}
