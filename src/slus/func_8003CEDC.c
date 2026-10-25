#include "types.h"
#include "addr.h"

extern s32 func_8002C338(s32, void*, s32);

static inline void func_8003CEAC(s32 idx, s32 id, s32 n) {
    func_8002C338(id, D_1F800024 + idx * 32, n);
}

void func_8003CEDC(u8* a0, s32 a1) {
    if (((s8*)a0)[2] == 0) {
        if (((s8*)a0)[0xF0] == 0) {
            func_8003CEAC(a1, 0, 1);
            func_8003CEAC(a1 + 1, 0x13, 1);
        }
    } else {
        func_8003CEAC(a1, 0, 1);
    }
}
