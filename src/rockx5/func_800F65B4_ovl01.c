#include "types.h"

extern s16 D_8009A0AA;
extern s16 D_8009A220[];

void func_800F65B4_ovl01(void) {
    if ((u16)(D_8009A0AA - 0x8C0) < 0xA9) {
        D_8009A220[1] = 0x60;
    }
}
