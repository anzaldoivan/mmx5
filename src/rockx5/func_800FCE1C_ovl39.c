#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];

void func_800FCE1C_ovl39(void* arg0, u8 arg1) {
    u8* p;
    u8* q;

    if (arg1) {
        p = D_8009A1F8;
        *(s16*)(p + 0x96) = 0x100;
        func_80016490(2, 0xA5, arg0);
    } else {
        q = D_8009A1F8;
        *(s16*)(q + 0x96) = 0;
    }
    p = D_8009A1F8;
    p[0xA0] = 1;
}
