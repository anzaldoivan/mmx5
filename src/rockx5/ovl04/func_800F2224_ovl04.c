#include "types.h"

extern s32 func_80030AE4(u8*, s16, s16);

s32 func_800F2224_ovl04(u8* obj) {
    s16 x;
    s16 y;
    u8* p;
    u8* q;

    if (obj[0x15] == 0) {
        x = *(s16*)(obj + 0xA) + (s8)(*(u8**)(obj + 0x68))[0];
    } else {
        x = *(s16*)(obj + 0xA) - (s8)(*(u8**)(obj + 0x68))[0];
    }
    p = *(u8**)(obj + 0x68);
    y = *(s16*)(obj + 0xE) + (s8)p[1];
    if (func_80030AE4(obj, p[2] + x, p[3] + y)) {
        return 1;
    }
    q = *(u8**)(obj + 0x68);
    if (func_80030AE4(obj, x - q[2], q[3] + y)) {
        return 1;
    }
    q = *(u8**)(obj + 0x68);
    if (func_80030AE4(obj, x - q[2], y - q[3])) {
        return 1;
    }
    q = *(u8**)(obj + 0x68);
    if (func_80030AE4(obj, q[2] + x, y - q[3]) == 0) {
        if (func_80030AE4(obj, x, y) == 0) {
            return 0;
        }
    }
    return 1;
}
