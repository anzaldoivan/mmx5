#include "types.h"

void func_8003A008(u8* p) {
    s32 hit;

    hit = 0;
    if (p[0x15] != 0) {
        hit = p[0x89] & 1;
        if (*(s32*)(p + 0x20) <= 0) {
            hit = 1;
        }
    } else {
        if (p[0x89] & 2) {
            hit = 1;
        }
        if (*(s32*)(p + 0x20) >= 0) {
            hit = 1;
        }
    }
    if (hit) {
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x28) = 0;
        p[6]++;
    }
}
