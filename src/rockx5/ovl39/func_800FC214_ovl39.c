#include "types.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u8 D_8009A1F8[];

void func_800FC214_ovl39(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE == 0x1F) {
            *(u16*)(arg0 + 0x7C) = 0x78;
            *(u16*)(arg0 + 0x7E) = 0;
            arg0[6]++;
            D_8009A1F8[0x3] = 0;
            D_8009A1F8[0x57] = 0;
            D_8009A1F8[0xAB] = 0;
        }
    }
}
