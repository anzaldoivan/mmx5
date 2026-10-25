#include "types.h"

extern void func_80016490(s32, s32, void*);

void func_800F4C20_ovl11(u8* p) {
    if (p[0x84] == 0) {
        if ((--p[0x83] & 1) == 0) {
            (*(s16*)(p + 0xE))++;
            if (((volatile u8*)p)[0x83] ==
                0) { // !FAKE: volatile forces the lbu 0x83 reload
                p[6] = p[0x87];
                func_80016490(5, 0x1D, p);
            }
        } else {
            (*(s16*)(p + 0xE))--;
        }
    } else {
        p[0x84]--;
    }
    if (p[0x84] == 1) {
        func_80016490(5, 0x1A, p);
    }
}
