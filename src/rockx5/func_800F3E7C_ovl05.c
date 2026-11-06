#include "types.h"

extern s32 func_8002D27C(void);
extern u8 D_8009A1F8[];
extern u16 D_800F5894_ovl05[];
extern u8 D_800F5964_ovl05[];

void func_800F3E7C_ovl05(u8* obj) {
    s32 i;
    u8* base;
    u8* s;
    s16 dx;

    i = obj[0x80];
    if (i < 3) {
        base = D_8009A1F8;
        do {
            dx = D_800F5894_ovl05[i] - *(u16*)(base + 0xA);
            if ((u16)dx < 0x141) {
                s = (u8*)func_8002D27C();
                if (s != 0) {
                    *(u8**)(s + 0x50) = obj;
                    s[0] = 0x41;
                    s[1] = 0x14;
                    s[2] = obj[0x80];
                    obj[0x80]++;
                    D_800F5964_ovl05[0] = 1;
                }
            }
        } while (++i < 3);
    }
}
