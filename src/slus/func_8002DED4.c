#include "types.h"

extern s32 D_8009A1AC;

void func_8002DED4(u8* p) {
    s32 t;

    *(s32*)(p + 0x8) += *(s32*)(p + 0x20);
    *(s32*)(p + 0xC) -= *(s32*)(p + 0x24);
    if (p[0x15] != 0) {
        *(s32*)(p + 0x20) += *(s32*)(p + 0x28);
    } else {
        *(s32*)(p + 0x20) -= *(s32*)(p + 0x28);
    }
    t = *(s32*)(p + 0x24) - *(s32*)(p + 0x2C);
    *(s32*)(p + 0x24) = t;
    if (t < D_8009A1AC) {
        *(s32*)(p + 0x24) = D_8009A1AC;
    }
}
