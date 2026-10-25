#include "types.h"

extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FA9D8_ovl53(u8* arg0) {
    u16 t;

    *(u16*)(arg0 + 6) += 1;
    t = *(u16*)(arg0 + 6);
    if (!(t & 3)) {
        if (D_800D50DE != 0x1F) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
        }
    }
    if (++*(s16*)(arg0 + 4) >= 0x19) {
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
