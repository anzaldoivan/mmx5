#include "types.h"

void func_8001DB78(u8* a) {
    s32 i;
    s32 j;
    u16 sum;
    u8* q;
    u8* e;
    u8* p;

    p = a;

    for (i = 0; i < 8; i++, p += 0x158) {
        if (p[0] != 0xFF) {
            sum = 0;
            q = p;
            e = p + 0x154;
            for (j = 0; j < e - p; j++) {
                sum += *q++;
            }
            sum += 0x55;
            if (*(u16*)(p + 0x154) != sum) {
                p[0] = 0xFF;
            }
        }
    }
}
