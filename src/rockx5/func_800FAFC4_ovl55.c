#include "types.h"

extern void func_8002385C(s32, s32, s32);

void func_800FAFC4_ovl55(u8* p) {
    if (*(s16*)(p + 4) < 0x5A) {
        (*(s16*)(p + 4))++;
    } else {
        func_8002385C(0x5C, 0xFF, 0);
        p[1]++;
    }
}
