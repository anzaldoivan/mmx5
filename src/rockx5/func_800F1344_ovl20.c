#include "types.h"

extern u8 D_8009A1F8[];

void func_800F1344_ovl20(u8* arg0) {
    u8* b;
    u8* c;
    u8* e;
    s16 d;

    b = D_8009A1F8;
    if (*(s16*)(b + 0x5E) < 0x281) {
        *(s16*)(b + 0x5E) += 8;
    } else {
        *(s16*)(b + 0x5E) -= 8;
    }
    c = D_8009A1F8;
    d = (*(s16*)(c + 0x5E) - 0x280) < 0 ? (0x280 - *(s16*)(c + 0x5E))
                                        : (*(s16*)(c + 0x5E) - 0x280);
    if (d < 8) {
        e = D_8009A1F8;
        *(s16*)(e + 0x5E) = 0x280;
        arg0[1] = 4;
        arg0[2] = 0;
    }
}
