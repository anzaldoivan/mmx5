#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];

void func_800EFCFC_ovl24(u8* p) {
    s32 flags;
    s32 i;
    s32 n;
    u8* q;
    u8* g;
    u8 st;
    u8 hp;
    u8 cb;

    flags = 0;
    g = D_800D1C00;
    st = g[0x26];
    if ((u32)(st - 1) < 8 && ((s8*)g)[0x27] == 0 &&
        !((D_8009A0A0[0xC9] >> ((s8)st - 1)) & 1)) {
        i = 0;
        n = 0;
        hp = p[0x79];
        for (; i < 8; i++) {
            if ((p[0x4C] >> i) & 1) {
                n++;
            }
        }
        if (n == 1) {
            flags = 1;
        } else if (n == 5 && hp < 5) {
            flags = 4;
        }
        if ((p[0x4C] & 0x35) == 0x35 && (D_8009A0A0[0xC9] & 0x35) != 0x35 &&
            p[0xCB] == 0) {
            if (hp >= 5) {
                goto out; // !FAKE: goto kept for the matching branch layout
            }
            flags |= 2;
        }
    }
    if (p[0x79] < 5) {
        if ((p[0x4C] & 0xCA) == 0xCA) {
            cb = p[0xCB];
            if (!(cb & 0x90) && (cb & 1)) {
                flags |= 8;
            }
        }
        if (*(s32*)(p + 0xAC) <= 0) {
            cb = p[0xCB];
            if (!(cb & 0x80) && (cb & 0x11) != 0x11) {
                flags |= 0x10;
            }
        }
    }
out:
    q = p + 0x194;
    n = 0;
    if (flags & 1) {
        p[0x194] = 2;
        n = 1;
    }
    if (flags & 4) {
        q[n++] = 7;
    }
    if (flags & 2) {
        q[n++] = 3;
        q[n++] = 4;
    }
    if (flags & 8) {
        q[n++] = 8;
    }
    if (flags & 0x10) {
        q[n++] = 0xF;
    }
    q[n] = 0xFF;
}
