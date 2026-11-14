#include "types.h"

extern u8 D_800C9318;
extern u8 D_8009A0A0[];
extern u8 D_80096D98[];
extern u8 D_800D1DC0[];
extern u8 D_800D1C00[];
extern s32 func_8002E274(u8* a0, u8* a1);
extern s32 func_80031670(u8* a0, s8 dmg);

s32 func_800317B8(u8* a0) {
    u8* p;
    s32 r;
    s32 n;
    s32 m;
    s32 e;
    u8* g;
    u8* h;
    u8* q;
    u8* o;
    s8 v;
    u8* b;
    s8 w;
    s8 k;
    s8 x;

    if (D_800C9318 != 0) {
        return 0;
    }
    p = D_8009A0A0;
    if (((s8*)p)[0x7A] == 1) {
        return 0;
    }
    if (((s8*)p)[0x7A] == 2 && (a0 < D_80096D98 || a0 >= D_80096D98 + 0x1380)) {
        return 0;
    }
    v = ((s8*)p)[0xD5];
    if (v < 0) {
        b = D_800D1DC0;
        if (v == -2) {
            b += 0xB0;
        }
        if (((s8*)b)[0x5C] & 0x80) {
            return 0;
        }
        if (b[0x85] != 0) {
            return 0;
        }
        if (((s8*)a0)[0x60] < 0) {
            return 0;
        }
        if (func_8002E274(a0, b) == 0) {
            return 0;
        }
        b[0x63] = 0;
        b[0x86] = 0;
        if (((s8*)a0)[0x60] < 5) {
            b[0x63] = 1;
        } else {
            b[0x63] = 2;
        }
        n = b[0x5C] - a0[0x60];
        g = D_800D1C00;
        b[0x5C] = n;
        *(s32*)(g + 0xB8) += ((s8*)a0)[0x60];
        if ((s8)n > 0) {
            b[0x5C] = n | 0x80;
        } else {
            g[0x1C] = 1;
            ((s8*)b)[0x5C] = -0x80;
        }
        if (*(s16*)(b + 0xA) >= *(s16*)(a0 + 0xA)) {
            b[0x84] = 0;
        } else {
            b[0x84] = 0x40;
        }
        return 1;
    }
    if (((s8*)a0)[0x60] < 0) {
        if (p[0xFB] & 0x80) {
            return 0;
        }
        w = ((s8*)p)[0x14B];
    } else {
        if (((s8*)p)[0x5C] & 0x80) {
            return 0;
        }
        w = ((s8*)p)[0xA4];
    }
    if (w != 0) {
        return 0;
    }
    if (func_8002E274(a0, p) == 0) {
        return 0;
    }
    if (((s8*)p)[0x7A] == 2) {
        p[0x7A] = 0;
    }
    if (((s8*)a0)[0x60] >= 0) {
        p[0x63] = a0[0x62];
        p[0xCA] = 0;
        switch (((s8*)a0)[0x62]) {
        case 0:
            if ((u8)(p[0xFA] - 1) < 4) {
                p[0x63] = 4;
            } else if (((s8*)a0)[0x60] < 5) {
                p[0x63] = 1;
            } else {
                p[0x63] = 2;
            }
            break;
        case 3:
            p[0xCA] = 1;
            break;
        case 5:
            p[0x63] = 5;
            break;
        case 6:
            p[0x63] = 6;
            break;
        case 7:
            p[0x63] = 7;
            break;
        case 8:
            p[0x63] = 8;
            break;
        case 9:
            p[0x63] = 9;
            break;
        }
    }
    r = func_80031670(p, ((s8*)a0)[0x60]);
    if (r < 0) {
        m = p[0xFB] - r;
        p[0xFB] = m;
        if ((u8)m >= 0x1F) {
            h = D_800D1C00;
            p[0xFB] = 0x9F;
            x = ((s8*)p)[2];
            *(u16*)(h + 0xBE) += 1;
            if (x != 0) {
                if (++h[0xA9] >= 0xE) {
                    h[0xA9] = 0xD;
                }
            }
        } else {
            p[0xFB] = m | 0x80;
        }
        return 1;
    }
    if (r == 0x7F) {
        q = D_800D1C00;
        *(s32*)(q + 0xB8) += ((s8*)p)[0x5C];
    } else {
        o = D_800D1C00;
        *(s32*)(o + 0xB8) += r;
    }
    e = p[0x5C] - r;
    p[0x5C] = e;
    if ((s8)e > 0) {
        p[0x5C] = e | 0x80;
    } else {
        D_800D1C00[0x1C] = 1;
        ((s8*)p)[0x5C] = -0x80;
    }
    k = ((s8*)a0)[0x62];
    if (k == 3) {
        return 1;
    }
    if ((u8)(a0[0x62] - 6) < 4) {
        if (a0[0x15] == 0) {
            p[0xA5] = 0x40;
        } else {
            p[0xA5] = 0;
        }
    } else if (k == 0) {
        if ((*(u32*)(p + 0xFC) & 0x20000) ||
            (((s8*)p)[2] != 0 && (D_800D1C00[0x4A] & 0x10))) {
            p[0xA5] = p[0x15];
        } else if (*(s16*)(p + 0xA) >= *(s16*)(a0 + 0xA)) {
            p[0xA5] = 0;
        } else {
            p[0xA5] = 0x40;
        }
    } else if (*(s16*)(p + 0xA) >= *(s16*)(a0 + 0xA)) {
        p[0xA5] = 0;
    } else {
        p[0xA5] = 0x40;
    }
    return 1;
}
