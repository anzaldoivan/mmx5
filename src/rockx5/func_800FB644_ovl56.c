#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern s32 func_80017E54(s32);

void func_800FB644_ovl56(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        func_80017E54(3);
        p = D_8009A1F8;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x400;
        p[0xA0] = 1;
        *(s16*)(arg0 + 4) = 0;
        *(s16*)(arg0 + 6) = 0;
        arg0[1]++;
    }
}
