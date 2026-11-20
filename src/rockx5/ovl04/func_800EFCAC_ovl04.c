#include "types.h"

extern u8* func_8002C938();
extern u8 D_8009A1F8[];
extern s8 D_800D1C26;

void func_800EFCAC_ovl04(u8* arg0) {
    u8* p = D_8009A1F8;
    u8* q;

    if (*(s16*)(p + 0xA) >= 0xB40) {
        *(s16*)(p + 0xA) = 0xB40;
        *(s16*)(p + 0x26) = 0xB40;
        *(s16*)(p + 0x1E) = 0xB40;
        q = func_8002C938();
        if (q != 0) {
            q[0] = 1;
            q[1] = 0x1E;
            q[2] = 9;
        }
        D_800D1C26 = 0;
        arg0[6]++;
    } else {
        *(s16*)(p + 0xA) += 2;
        *(s16*)(p + 0x1E) += 2;
        *(s16*)(p + 0x26) += 2;
    }
}
