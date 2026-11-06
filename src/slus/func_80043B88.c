#include "types.h"

extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern s32 func_8003E6FC(void*, s8);

s32 func_80043B88(u8* arg0) {
    u8* p;
    s32 cost;

    if (*(s8*)(arg0 + 2) == 0) {
        return 0;
    }
    if (*(s8*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(arg0 + 0x93) != 3) {
        return 0;
    }
    if (!(*(u16*)(arg0 + 0x80) & 0x20)) {
        return 0;
    }
    if (*(s8*)(arg0 + 0xA6) != 0) {
        return 0;
    }
    cost = func_8003E6FC(arg0, 3);
    if (*(s16*)(arg0 + 0xAE) < cost) {
        return 0;
    }
    p = func_8003D3A8(1, 0x2B, 0, arg0);
    if (p != 0) {
        *(s16*)(arg0 + 0xAE) -= func_8003E6FC(arg0, 3);
        p[0x99] = 0;
    }
    return 0;
}
