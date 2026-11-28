#include "types.h"

extern void func_8003C5D8();
extern void func_8003CEDC(u8* arg0, s32 arg1);

void func_8003C4C0(u8* p) {
    s8 st;
    s8 a1;

    st = *(s8*)(p + 5);
    if (st == 0) {
        return;
    }
    if (st == 1) {
        return;
    }
    if (*(s8*)(p + 0xA4) > 0) {
        return;
    }
    if (*(s8*)(p + 0xA2) != 0) {
        p[0xA2] = p[0xA2] - 1;
        if ((*(s8*)(p + 0xA2) << 24) == 0) {
            func_8003C5D8();
        }
    }
    if (*(s8*)(p + 0xA4) < 0) {
        p[0xA1] = 0x23;
    } else {
        s8 k = *(s8*)(p + 0x14B);
        if (k != 0) {
            if (k > 0) {
                p[0xA1] = 0x50;
            } else {
                func_8003CEDC(p, 0x50);
                return;
            }
        }
    }
    a1 = *(s8*)(p + 0xA1);
    if (a1 != 0) {
        if (*(s8*)(p + 0x9F) != 0) {
            p[0x9F] = p[0x9F] - 1;
        } else {
            if (*(s8*)(p + 0xA0) == 0) {
                func_8003CEDC(p, a1);
            } else {
                func_8003C5D8(p);
            }
            p[0x9F] = 1;
            p[0xA0] ^= 1;
        }
        p[0xA1] = 0;
    }
}
