#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8002385C(s32, s32, s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FA700_ovl44(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        func_80016490(2, 0x4B, 0);
        p = D_8009A1F8;
        *(s16*)(p + 0xB6) = 0x200;
        p[0xF4] = 1;
        func_8002385C(0x15, 0xFF, 0);
        arg0[1]++;
    }
}
