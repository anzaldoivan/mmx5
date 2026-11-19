#include "types.h"

extern u8 D_8009A199;

#define HB(o) (*(u8**)((o) + 0x68))

void func_8002ECB0(u8* arg0, u8* arg1, u32 arg2) {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s32 a;
    s32 h1;
    s32 h2;
    s32 h3;
    s32 h4;
    s32 t;
    u8 flags;

    flags = 0;
    if (arg0[0x15] == 0x40) {
        x0 = *(s16*)(arg0 + 0xA) - (s8)HB(arg0)[0];
    } else {
        x0 = *(s16*)(arg0 + 0xA) + (s8)HB(arg0)[0];
    }
    y0 = *(s16*)(arg0 + 0xE) + (s8)HB(arg0)[1];
    if (arg1[0x15] == 0x40) {
        x1 = *(s16*)(arg1 + 0xA) - (s8)HB(arg1)[0];
    } else {
        x1 = *(s16*)(arg1 + 0xA) + (s8)HB(arg1)[0];
    }
    y1 = *(s16*)(arg1 + 0xE) + (s8)HB(arg1)[1];

    a = (s16)(((y0 - y1) < 0) ? (y1 - y0) : (y0 - y1));
    h1 = HB(arg0)[3];
    if (a == HB(arg1)[3] + h1) {
        a = (s16)(((x0 - x1) < 0) ? (x1 - x0) : (x0 - x1));
        h2 = HB(arg0)[2];
        t = HB(arg1)[2];
        h2 = -h2; // !FAKE: t - (-h) keeps the addu operand order (C0356)
        a = a < t - h2;
        if (a) {
            flags = 8;
            if (y0 < y1) {
                flags = 4;
            }
        }
    }
    a = (s16)(((x0 - x1) < 0) ? (x1 - x0) : (x0 - x1));
    h3 = HB(arg0)[2];
    if (a == HB(arg1)[2] + h3) {
        a = (s16)(((y0 - y1) < 0) ? (y1 - y0) : (y0 - y1));
        h4 = HB(arg0)[3];
        t = HB(arg1)[3];
        h4 = -h4; // !FAKE: t - (-h) keeps the addu operand order (C0356)
        a = a < t - h4;
        if (a) {
            if (x0 < x1) {
                flags |= 2;
            } else {
                flags |= 1;
            }
            arg1[0x4A] = arg0[0x75];
        }
    }
    switch (arg2) {
    case 0:
        arg0[0x72] = flags;
        break;
    case 1:
        arg0[0x73] = flags;
        break;
    case 2:
        arg0[0x74] = flags;
        break;
    }
    arg1[0x71] = arg1[0x71] | flags;
    if (flags & 0xB) {
        switch (arg2) {
        case 0:
            arg0[0x76] = 1;
            break;
        case 1:
            arg0[0x77] = 1;
            break;
        case 2:
            arg0[0x78] = 1;
            break;
        }
    } else {
        switch (arg2) {
        case 0:
            arg0[0x76] = 0;
            break;
        case 1:
            arg0[0x77] = 0;
            break;
        case 2:
            arg0[0x78] = 0;
            break;
        }
    }
    if (flags != 0) {
        D_8009A199 = arg0[0x60];
    }
}
