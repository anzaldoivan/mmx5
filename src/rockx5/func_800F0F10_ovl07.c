#include "types.h"

extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8002A600(s32, s32, s32);
extern void func_8002A5C4(s32, s32, s32);

void func_800F0F10_ovl07(u8* p) {
    (*(u16*)(p + 0x9C))++;
    if (*(u16*)(p + 0x9C) < 120) {
        if ((*(volatile u16*)(p + 0x9C) & 7) ==
            0) { // !FAKE: volatile re-read of the counter
            func_8004FD90(p, 1, 0x30, 0x30);
            func_8004FD90(p, 1, 0x30, 0x30);
            func_8004FD90(p, 1, 0x30, 0x30);
            func_8004FD90(p, 1, 0x30, 0x30);
        }
    } else {
        *(u16*)(p + 0x9C) = 0;
        p[5]++;
        func_8002A600(100, 3, 2);
        func_8002A5C4(100, 2, 1);
        *(s16*)(p + 0xE) = 0xD0;
    }
}
