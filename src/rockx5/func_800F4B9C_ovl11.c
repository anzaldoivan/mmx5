#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_8003D2C4(void);

void func_800F4B9C_ovl11(u8* p) {
    p[0x83]--;
    if ((p[0x83] & 1) == 0) {
        (*(s16*)(p + 0xE))++;
        if (((volatile u8*)p)[0x83] == 0) { // !FAKE: volatile forces the reload
            func_80016490(5, 0x1D, p);
            p[6] = 3;
            func_8003D2C4();
        }
    } else {
        (*(s16*)(p + 0xE))--;
    }
}
