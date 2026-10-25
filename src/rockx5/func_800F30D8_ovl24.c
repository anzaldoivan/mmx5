#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_8002C50C(void);
extern u16 D_800C9320;
extern u8 D_8009A427;

void func_800F30D8_ovl24(u8* arg0) {
    if (D_800C9320 & 0x40) {
        func_80016490(0, 0x22, 0);
        func_8002C50C();
        D_8009A427 = 0;
        arg0[1] = 9;
        arg0[2] = 0;
    }
}
