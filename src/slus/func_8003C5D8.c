#include "types.h"
#include "addr.h"

extern s32 func_8002C338(s32, void*, s32);
extern void func_8003CEDC(u8* arg0, s32 arg1);
extern u8 D_800D1C4A;

static inline void func_8003CEAC(s32 idx, s32 id, s32 n) {
    func_8002C338(id, D_1F800024 + idx * 32, n);
}

void func_8003C5D8(u8* arg0) {
    s32 flags;
    s8 idx;

    if (((s8*)arg0)[2] == 0) {
        if (((s8*)arg0)[0xF0] == 0) {
            idx = ((s8*)arg0)[0x93];
            if (idx == 0) {
                func_8003CEDC(arg0, 0);
            } else {
                if (idx != 7) {
                    func_8003CEAC(idx * 4 - 1, 1, 1);
                }
                func_8003CEAC(((s8*)arg0)[0x93] * 4, 0, 1);
                func_8003CEAC(((s8*)arg0)[0x93] * 4 + 1, 0x13, 1);
            }
            if (arg0[0xFA] != 3) {
                flags = *(s32*)(arg0 + 0xFC);
                if (flags & 0x100) {
                    func_8003CEAC(0x4F, 0x14, 1);
                    return;
                }
                if (flags & 0x200) {
                    func_8003CEAC(0x4E, 0x14, 1);
                    return;
                }
                if (flags & 0x800) {
                    func_8003CEAC(0x4D, 0x14, 1);
                }
            }
        }
    } else {
        if (D_800D1C4A & 0x10) {
            func_8003CEAC(0xD, 0, 1);
            func_8003CEAC(0x5C, 0xD, 3);
            return;
        }
        func_8003CEAC(0, 0, 1);
    }
}
