#include "types.h"

extern s32 func_8002DF78(void);
extern u8 D_8009A1F8[];

void func_800FAC34_ovl55(u8* arg0) {
    u8* p;
    u8* q;

    if (++*(u16*)(arg0 + 4) & 1) {
        p = D_8009A1F8;
        *(s16*)(p + 0xA) = func_8002DF78() % 9;
        *(s16*)(p + 0xE) = func_8002DF78() % 5;
    } else {
        u8* r = D_8009A1F8;
        *(s16*)(r + 0xA) = 0;
        *(s16*)(r + 0xE) = 0;
    }
    q = D_8009A1F8;
    q[0x4C] = 1;
    if (*(s16*)(arg0 + 4) >= 0xF1) {
        *(s16*)(q + 0xA) = 0;
        *(s16*)(q + 0xE) = 0;
        *(s16*)(arg0 + 4) = 0;
        *(s16*)(arg0 + 6) = 0;
        arg0[1]++;
    }
}
