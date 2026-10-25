#include "types.h"

extern int func_8002D6FC();
extern u16 D_8009A22C;
extern u8 D_800D1C00[];

void func_800FE8F8_ovl04(void) {
    if (D_8009A22C == 0) {
        u8* p = D_800D1C00;
        p[0x26] |= 4;
        func_8002D6FC();
    }
}
