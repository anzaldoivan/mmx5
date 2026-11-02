#include "types.h"

extern u8 D_8009A420[];
extern u16 D_800C9320;
extern s32 func_80016490(s32, s32, void*);
extern void func_800132F8(s8 arg);
extern void func_800211C4(void*, s32);

void func_80020164(u8* arg0) {
    u8* p = D_8009A420;

    if (((s8*)p)[4] == 0) {
        if (D_800C9320 & 0x40) {
            func_80016490(0, 0x22, 0);
            if (p[7] != 1) {
                func_800132F8(8);
            }
            arg0[1]++;
            *(s16*)(arg0 + 0xA) = p[7];
        } else if (D_800C9320 & 0x10) {
            func_800132F8(8);
            *(s16*)(arg0 + 0xA) = 2;
            arg0[1]++;
        } else {
            func_800211C4(p + 7, *(s16*)(arg0 + 8));
        }
    }
}
