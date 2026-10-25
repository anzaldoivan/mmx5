#include "types.h"

extern void func_8002C1C8(void);
extern s32 func_80017E54(s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FB020_ovl55(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        p[0x3] = 0;
        p[0x57] = 0;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x300;
        p[0xF4] = 1;
        func_8002C1C8();
        arg0[1]++;
        func_80017E54(3);
    }
}
