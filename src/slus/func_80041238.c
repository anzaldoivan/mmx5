#include "types.h"

extern s32 func_8002DF78(void);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern void func_8003B33C(u8*, s32);
extern s8 D_800E9548;

void func_80041238(u8* obj) {
    if (--obj[0xF4] == 0) {
        obj[0xF4] = func_8002DF78() % 3 + 3;
        func_8003D3A8(1, 0x31, D_800E9548, 0);
        D_800E9548 ^= 1;
    }
    if (++((s8*)obj)[7] >= 0x79) {
        obj[6]++;
        if (obj[0x17] >= 0xB1) {
            func_8003B33C(obj, 0xB3);
        } else {
            func_8003B33C(obj, 0xB0);
        }
    }
}
