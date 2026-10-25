#include "types.h"

extern s32 func_8004111C(u8* a0);
extern s32 func_8003FE6C(u8* a0);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);

void func_8004103C(u8* a0) {
    s32 n;

    if (func_8004111C(a0) == 0) {
        n = func_8003FE6C(a0);
        if (n != 0) {
            a0[6] = n + 1;
            func_8003B4CC(a0, n + 0xAA, ((s8*)a0)[0x45]);
        }
    }
}
