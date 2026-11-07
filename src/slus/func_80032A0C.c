#include "types.h"

extern s32 func_8002E804(u8*, u8*);
extern void func_8002EAB0(u8*, u8*);
extern void func_8002EBEC(u8*, u8*);

s32 func_80032A0C(u8* arg0, u8* arg1) {
    s32 t;
    s16 x;
    s32 uy;
    s16 y;
    s8 dir;

    if (*(s32*)(arg1 + 0x68) == 0) {
        return 0;
    }
    if (func_8002E804(arg0, arg1) != 0) {
        func_8002EAB0(arg0, arg1);
        func_8002EBEC(arg0, arg1);
        t = *(s16*)(arg1 + 0x6C);
        x = t;
        if (t < 0) {
            x = -*(u16*)(arg1 + 0x6C);
        }
        y = *(s16*)(arg1 + 0x6E);
        uy = *(u16*)(arg1 + 0x6E);
        if (y < 0) {
            y = -uy;
        }
        dir = *(s8*)(arg0 + 0x66);
        if (dir == 0 ? x < y : dir > 0) {
            *(u16*)(arg1 + 0xA) += *(u16*)(arg1 + 0x6C);
        } else {
            *(u16*)(arg1 + 0xE) += uy;
        }
        return 1;
    }
    return 0;
}
