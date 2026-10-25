#include "types.h"

void func_800F1BD4_ovl10(u8* arg0, u8 arg1);

void func_800F18C4_ovl10(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        func_800F1BD4_ovl10(arg0, 0x10);
        func_800F1BD4_ovl10(arg0, 0x12);
        func_800F1BD4_ovl10(arg0, 0x11);
        func_800F1BD4_ovl10(arg0, 0x13);
        *(s16*)(arg0 + 0x7C) = 0x28;
        arg0[6]++;
    }
}
