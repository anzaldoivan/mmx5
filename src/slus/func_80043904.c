#include "types.h"

extern s32 func_80044328(u8*);
extern void func_8003B33C(u8*, s32);
extern s32 func_80016490(s32, s32, void*);
extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern void func_80042770(u8*);

s32 func_80043904(u8* arg0) {
    if (func_80044328(arg0) == 0) {
        return 0;
    }
    if (arg0[0xC9] & 1) {
        func_8003B33C(arg0, 0x60);
        func_80016490(1, 7, arg0);
        func_8003D4C0(1, 0x11, 0, (s32)arg0);
        arg0[5] = 0x35;
    } else {
        func_8003B33C(arg0, 0x5B);
        func_80016490(1, 8, arg0);
        arg0[5] = 0x31;
    }
    arg0[6] = 0;
    func_80042770(arg0);
    return 1;
}
