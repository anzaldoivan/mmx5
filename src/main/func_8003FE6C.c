#include "types.h"

extern u8 D_80074D24[];

s32 func_8003FE6C(u8* arg0) {
    u16 f0;
    u16 flags;
    s32 w;
    s32 v;
    s32 m;

    f0 = *(u16*)(arg0 + 0x7C);
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    if (!(f0 & 0xF)) {
        *(u16*)(arg0 + 0xE) += (s8)D_80074D24[arg0[0xE9]];
        arg0[0xE9] = (arg0[0xE9] + 1) & 0xF;
        return 0;
    }
    if (f0 & 2) {
        arg0[0x15] = 0;
    } else if (f0 & 1) {
        arg0[0x15] = 0x40;
    }
    w = *(s32*)(arg0 + 0x104);
    flags = *(u16*)(arg0 + 0x7C);
    v = w + w / 2;
    if (flags & 4) {
        if (flags & 1) {
            s32 a;

            if (arg0[0x89] & 5) {
                return 0;
            }
            a = (v >> 8) * 0xB5;
            *(s32*)(arg0 + 0x20) = a;
            *(s32*)(arg0 + 0x24) = a;
        } else if (flags & 2) {
            s32 a;

            if (arg0[0x89] & 6) {
                return 0;
            }
            a = (v >> 8) * 0xB5;
            *(s32*)(arg0 + 0x20) = -a;
            *(s32*)(arg0 + 0x24) = a;
        } else {
            if (arg0[0x89] & 4) {
                return 0;
            }
            *(s32*)(arg0 + 0x24) = v;
        }
        return 2;
    }
    if (flags & 8) {
        if (flags & 1) {
            s32 a;

            if (arg0[0x89] & 9) {
                return 0;
            }
            a = (v >> 8) * 0xB5;
            *(s32*)(arg0 + 0x20) = a;
            m = -a;
        } else if (flags & 2) {
            s32 a;

            if (arg0[0x89] & 0xA) {
                return 0;
            }
            a = (v >> 8) * 0xB5;
            m = -a;
            *(s32*)(arg0 + 0x20) = m;
        } else {
            if (arg0[0x89] & 8) {
                return 0;
            }
            m = -v;
        }
        *(s32*)(arg0 + 0x24) = m;
        return 3;
    }
    if (flags & 1) {
        if (arg0[0x89] & 1) {
            return 0;
        }
        *(s32*)(arg0 + 0x20) = v;
    } else {
        if (arg0[0x89] & 2) {
            return 0;
        }
        *(s32*)(arg0 + 0x20) = -v;
    }
    return 1;
}
