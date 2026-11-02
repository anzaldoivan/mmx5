#include "types.h"

extern void func_8003C5D8(u8* obj);
extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);

void func_8003DF20(u8* obj) {
    s8 state;

    func_8003C5D8(obj);
    state = *(s8*)(obj + 0x93);
    if (state == 1) {
        func_8003D4C0(1, 0x1B, 0, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            func_8003D4C0(1, 0x1B, 0xC, 0);
        }
    } else if (state == 3) {
        func_8003D4C0(1, 0x1B, 1, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            func_8003D4C0(1, 0x1B, 0xB, 0);
        }
    } else if (state == 4) {
        func_8003D4C0(1, 0x1B, 2, 0);
    } else if (state == 5) {
        func_8003D4C0(1, 0x1B, 3, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            func_8003D4C0(1, 0x1B, 0xD, 0);
        }
    } else if (state == 7) {
        func_8003D4C0(1, 0x1B, 4, 0);
    } else if (state == 8) {
        func_8003D4C0(1, 0x1B, 5, 0);
    } else if (state == 6) {
        func_8003D4C0(1, 0x1B, 6, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            func_8003D4C0(1, 0x1B, 0xA, 0);
        }
    }
}
