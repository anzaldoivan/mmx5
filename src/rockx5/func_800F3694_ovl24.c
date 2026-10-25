#include "types.h"

extern void func_800211C4(void*, s32);
extern void func_80016490(s32, s32, void*);
extern s32 func_800132F8(s8 arg);
extern void func_8002C50C(void);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A420[];
extern u16 D_800C9320;
extern u8 D_80070F5C[];

void func_800F3694_ovl24(u8* arg0) {
    func_800211C4(&D_8009A420[7], *(s16*)(arg0 + 8));
    if (D_800C9320 & 0x40) {
        func_80016490(0, 0x22, 0);
        if (D_8009A420[7] == 0) {
            func_800132F8(8);
            arg0[2] = 3;
            arg0[3] = 0;
        } else {
            func_8002C50C();
            *(s16*)(arg0 + 8) = func_8001FF18(D_80070F5C, 1);
            D_8009A420[7] = 1;
            arg0[2]++;
        }
    }
}
