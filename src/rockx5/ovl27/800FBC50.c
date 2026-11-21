#include "types.h"

void func_800FBC50_ovl27(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x7C);
    if (p[0x8C] & 0xE) {
        p[0x89] = 1;
    } else {
        p[0x89] = 2;
    }
    arg0[6]++;
}

void func_800FBC88_ovl27(u8* arg0) {
    if ((*(u8**)(arg0 + 0x7C))[0x89] == 0) {
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
