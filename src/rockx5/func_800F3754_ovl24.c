#include "types.h"

extern void func_800211C4(void*, s32);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_800132F8(s8 arg);
extern void func_8002C50C(void);
extern u8 D_8009A420[];
extern u16 D_800C9320;

void func_800F3754_ovl24(u8* arg0) {
    func_800211C4(&D_8009A420[7], *(s16*)(arg0 + 8));
    if (D_800C9320 & 0x40) {
        func_80016490(0, 0x22, 0);
        if (D_8009A420[7] == 0) {
            func_800132F8(8);
            arg0[2] = 3;
            arg0[3] = 1;
        } else {
            func_8002C50C();
            arg0[2] = 0;
        }
    }
}
