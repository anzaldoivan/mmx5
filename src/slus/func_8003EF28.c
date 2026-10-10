#include "types.h"

extern s32 func_8003E1A8(u8*);
extern void func_8003E414(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_8003F548(u8*, s32);
extern signed char D_80074968[];

s32 func_8003EF28(u8* arg0) {
    signed char idx;

    if (*(signed char*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    if (*(signed char*)(arg0 + 0x2) != 0) {
        return 0;
    }
    if (func_8003E1A8(arg0) != 0) {
        return 1;
    }
    func_8003E414(arg0);
    if (*(signed char*)(arg0 + 0x8F) == 0) {
        return 0;
    }
    idx = *(signed char*)(arg0 + 0x96);
    if (D_80074968[idx] == 0) {
        return 0;
    }
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    arg0[0x8C] = 0;
    if (idx == 6) {
        func_8003B33C(arg0, 0x58);
    }
    func_8003F548(arg0, 0);
    return 1;
}
