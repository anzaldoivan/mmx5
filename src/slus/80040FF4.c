#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_80040FF4(u8* p) {
    if (*(s8*)(p + 0x46) == 0) {
        func_8003B33C(p, 0xAA);
        p[6]++;
    }
}

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

extern s32 func_8004111C(u8* a0);
extern s32 func_8003FE6C(u8* a0);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);

void func_80041090(u8* a0) {
    s32 n;

    if (func_8004111C(a0) == 0) {
        n = func_8003FE6C(a0);
        if (n != 0) {
            if (n != ((s8*)a0)[6] - 1) {
                a0[6] = n + 1;
                func_8003B4CC(a0, n + 0xAA, ((s8*)a0)[0x45]);
            } else {
                move_object(a0);
            }
        } else {
            func_8003B33C(a0, 0xAA);
            a0[6] = 1;
        }
    }
}
