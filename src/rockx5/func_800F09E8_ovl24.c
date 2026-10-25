#include "types.h"

extern u8 D_8009A420[];
extern u16 D_800C9320;

extern void func_800211C4(void*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_800132F8(s8 arg);

void func_800F09E8_ovl24(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        func_800211C4(p + 7, *(s16*)(arg0 + 8));
        if (D_800C9320 & 0x40) {
            func_80016490(0, 0x22, 0);
            func_800132F8(8);
            arg0[2]++;
        }
    }
}
