#include "types.h"

extern s16 D_8009A202;
extern s16 D_8009A206;

s32 func_8002E408(u8* a, u8* b, s16* outx, s16* outy) {
    u8* ha;
    u8* hb;
    s32 wa;
    s32 wb;
    s32 sum;
    s32 sb;
    s32 sa;
    s32 ax;
    s32 bx;
    s32 d;
    s32 ad;
    u8* yb;

    if (((s8*)b)[0x61] != 0) {
        return 0;
    }
    ha = *(u8**)(a + 0x50);
    if (ha == 0) {
        return 0;
    }
    hb = *(u8**)(b + 0x54);
    if (hb == 0) {
        return 0;
    }

    sa = ((volatile u8*)ha)[2]; // !FAKE: target reloads both widths
    sb = ((volatile u8*)hb)[2]; // !FAKE: target reloads both widths
    sb = -sb; // !FAKE: sa - (-sb) keeps the addu operand order of the target
    sum = sa - sb;
    wa = ha[2];
    wb = hb[2];

    if (((s8*)a)[0x14] < 0) {
        if (a[0x15] & 0x40) {
            ax = *(s16*)(a + 0xA) - ((s8*)ha)[0] + D_8009A202;
        } else {
            ax = *(s16*)(a + 0xA) + ((s8*)ha)[0] + D_8009A202;
        }
    } else {
        if (a[0x15] & 0x40) {
            ax = *(s16*)(a + 0xA) - ((s8*)ha)[0];
        } else {
            ax = *(s16*)(a + 0xA) + ((s8*)ha)[0];
        }
    }
    if (b[0x15] & 0x40) {
        bx = *(s16*)(b + 0xA) - ((s8*)hb)[0];
    } else {
        bx = *(s16*)(b + 0xA) + ((s8*)hb)[0];
    }

    d = bx - ax;
    ad = (bx - ax) < 0 ? (ax - bx) : (bx - ax);

    if (bx < ax) {
        if (a[0x15] & 0x40) {
            if (b[0x15] & 0x40) {
                if (!(ad < wa)) {
                    return 0;
                }
                if (ax < bx) {
                    *outx = bx + (wa - ad) / 2;
                } else if (wa < wb + ad) {
                    *outx = bx + (wa - ad) / 2;
                } else {
                    *outx = bx - wb / 2;
                }
            } else {
                if (!(ad < sum)) {
                    return 0;
                }
                if (bx >= ax - wa && wb < ad) {
                    *outx = wb / 2 + bx;
                } else if (bx + wb >= ax && wa < ad) {
                    *outx = ax - wa / 2;
                } else if (ax - wa < bx) {
                    *outx = bx + ad / 2;
                } else {
                    *outx = (ax - wa) + ((bx + wb) - (ax - wa)) / 2;
                }
            }
        } else {
            if (b[0x15] & 0x40) {
                return 0;
            }
            if (!(ad < wb)) {
                return 0;
            }
            if (ax >= bx && wb >= ad + wa) {
                *outx = wa / 2 + ax;
            } else {
                *outx = ax + (wb - ad) / 2;
            }
        }
    } else {
        if (a[0x15] & 0x40) {
            if (!(b[0x15] & 0x40)) {
                return 0;
            }
            if (!(ad < wb)) {
                return 0;
            }
            if (wb >= ad + wa) {
                *outx = ax - wa / 2;
            } else {
                *outx = ax - (wb - ad) / 2;
            }
        } else {
            if (b[0x15] & 0x40) {
                if (!(ad < sum)) {
                    return 0;
                }
                if (wa < ad) {
                    *outx = wa / 2 + ax;
                } else if (wb < ad) {
                    *outx = bx - wb / 2;
                } else {
                    *outx = bx - d / 2;
                }
            } else {
                if (!(ad < wa)) {
                    return 0;
                }
                if (!(wa < ad + wb)) {
                    *outx = wb / 2 + bx;
                }
                *outx = bx + (wa - ad) / 2;
            }
        }
    }

    if (((s8*)a)[0x14] < 0) {
        ax = *(s16*)(a + 0xE) + ((s8*)*(u8**)(a + 0x50))[1] + D_8009A206;
    } else {
        ax = *(s16*)(a + 0xE) + ((s8*)*(u8**)(a + 0x50))[1];
    }
    wa = (*(u8**)(a + 0x50))[3];
    yb = *(u8**)(b + 0x54);
    bx = *(s16*)(b + 0xE) + ((s8*)yb)[1];
    wb = yb[3];

    ad = (bx - ax) < 0 ? (ax - bx) : (bx - ax);

    if (bx < ax) {
        if (!(ad < wb)) {
            return 0;
        }
        if (ax >= bx && wb >= ad + wa) {
            *outy = wa / 2 + ax;
        } else {
            *outy = ax + (wb - ad) / 2;
        }
    } else {
        if (!(ad < wa)) {
            return 0;
        }
        if (wa >= ad + wb) {
            *outy = wb / 2 + bx;
        } else {
            *outy = bx + (wa - ad) / 2;
        }
    }
    return 1;
}
