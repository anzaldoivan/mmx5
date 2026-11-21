#include "types.h"

void func_800F144C_ovl04(u8* arg0) {
    *(s16*)(arg0 + 0x7C) = 0x78;
    *(s16*)(arg0 + 0x7E) = 0;
    arg0[6]++;
}

void func_800F1468_ovl04(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == -1) {
        *(s16*)(arg0 + 0x7C) = 0x78;
        if ((*(u16*)(arg0 + 0x7E) ^= 1) == 0) {
            func_800F15B8_ovl04(arg0, 0x10);
            func_800F15B8_ovl04(arg0, 0x11);
            func_800F15B8_ovl04(arg0, 0x12);
        } else {
            func_800F15B8_ovl04(arg0, 0x20);
            func_800F15B8_ovl04(arg0, 0x21);
            func_800F15B8_ovl04(arg0, 0x22);
        }
    }
}
