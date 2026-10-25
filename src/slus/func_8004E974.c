#include "types.h"

extern u8 D_800D1F2B;
extern void func_8002D89C(u8*);

void func_8004E974(u8* a0) {
    if ((a0[2] & 0x3F) == 3) {
        a0[0x47] = (s8)D_800D1F2B / 10 + 12;
    } else {
        a0[0x47] = (s8)D_800D1F2B % 10 + 12;
    }
    func_8002D89C(a0);
}
