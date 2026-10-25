#include "types.h"

extern void func_800132F8(s8 arg);
extern u16 D_800C9320;

void func_800F035C_ovl25(u8* arg0) {
    if (D_800C9320 != 0) {
        func_800132F8(8);
        arg0[1] = 10;
    } else if (--*(s16*)(arg0 + 4) == 0) {
        arg0[1]++;
    }
}
