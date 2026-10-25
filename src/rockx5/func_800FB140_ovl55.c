#include "types.h"

extern u8 D_800D1F3C;
extern u8 D_8009A1F8[];
extern u8* D_800FD2B8_ovl55;

extern u8* func_8002D53C(void);

void func_800FB140_ovl55(u8* e) {
    u8* p;
    u8* q;

    if (D_800D1F3C == 2) {
        p = D_8009A1F8;
        p[3] = 0;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0x200;
        *(s16*)(p + 0x62) = 0x80;
        p[0xA0] = 1;
        p[0xAB] = 0;
        q = func_8002D53C();
        if (q != 0) {
            q[0] = 1;
            q[1] = 10;
            q[0x36] = 0x11;
            q[2] = 0;
            D_800FD2B8_ovl55 = q;
        }
        e[1]++;
    }
}
