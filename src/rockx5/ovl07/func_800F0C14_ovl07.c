#include "types.h"

extern void func_800F0CA8_ovl07(u8* arg0);

void func_800F0C14_ovl07(u8* arg0) {
    if (*(s8*)(arg0 + 0x9B) != 0 && arg0[0x9A] != 0) {
        if (*(s8*)(arg0 + 0x61) == 0) {
            arg0[0x9A] = 0;
            arg0[0x85] = 0;
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
            func_800F0CA8_ovl07(arg0);
        } else {
            arg0[0x61]--;
            if (arg0[0x61] & 2) {
                *(u16*)(arg0 + 0x42) |= 0x8000;
            } else {
                *(u16*)(arg0 + 0x42) &= 0x7FFF;
            }
        }
    }
}
