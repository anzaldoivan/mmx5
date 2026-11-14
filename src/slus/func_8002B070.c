#include "types.h"
#include "addr.h"

extern u8* D_80072EAC[][2];
extern s8 D_800D1C00[];
extern u8 D_8009A1F8[];
extern s16 D_80072DC8[];
extern u32* D_80098118;
extern s32 func_8002AFB4(u8*);
extern u8* func_8002B4E4(s32);
extern s32 func_8002B5B4(s32);

void func_8002B070(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    u8* p;
    u8* o;
    s16 x0, x1, y0, y1;
    s16 d;
    s16 lx0, lx1, ly0, ly1;
    s16 px;
    s32 t, u;
    s32 ok;
    u8 b;
    s32 c;
    s32 e;
    u8* bg;

    p = D_80072EAC[D_800D1C00[0xC]][D_800D1C00[0xD]];
    bg = D_8009A1F8;
    lx0 = *(u16*)(bg + 0xA) - 0x30;
    lx1 = *(u16*)(bg + 0xA) + 0x170;
    ly0 = *(u16*)(bg + 0xE) - 0x30;
    ly1 = *(u16*)(bg + 0xE) + 0x120;

    while (p[3] != 0xF) {
        b = p[0];
        if (!(b & 0x81)) {
            x0 = arg0;
            x1 = arg1;
            y0 = arg2;
            y1 = arg3;
            if (b & 0x70) {
                d = D_80072DC8[(b >> 4) - 1];
                switch (arg4) {
                case 1:
                    x1 += d;
                    x0 += d;
                    break;
                case 2:
                    x0 -= d;
                    x1 -= d;
                    break;
                case 3:
                    y1 += d;
                    y0 += d;
                    break;
                case 4:
                    y0 -= d;
                    y1 -= d;
                    break;
                }
            }
            if (x0 < *(s16*)(p + 4) && *(s16*)(p + 4) < x1 &&
                y0 < *(s16*)(p + 6) && *(s16*)(p + 6) < y1) {
                if (func_8002AFB4(p) == 0) {
                    o = func_8002B4E4(p[3]);
                    if (o != 0) {
                        o[0] = 0x41;
                        o[1] = p[1];
                        o[2] = p[2];
                        *(s16*)(o + 0xA) = *(s16*)(p + 4);
                        *(s16*)(o + 0xE) = *(s16*)(p + 6);
                        *(u8**)(o + 0x10) = p;
                        if ((p[3] & 0xF) < 3) {
                            *(u16*)(o + 0x40) =
                                D_80098118[func_8002B5B4(p[1])] >> 7;
                            t = func_8002B5B4(p[1]);
                            u = func_8002B5B4(p[1]);
                            *(u16*)(o + 0x42) = ((t * 4 + 0x18) % 16) |
                                                (((u + 6) / 4 + 0x1E0) << 6);
                            *(s32*)(o + 0x3C) =
                                (s32)D_1F800020.s32s +
                                D_1F800020.s32s[func_8002B5B4(p[1])];
                        }
                        p[0] |= 1;
                    }
                }
            } else {
                e = p[3];
                // test before the copy, and e reused for the y read below: keeps c a separate copy in a1
                ok = (u32)(e & 0xF) < 3;
                c = e;
                if (ok) {
                    px = *(s16*)(p + 4);
                    if (px < lx0 || lx1 < px || (e = *(s16*)(p + 6)) < ly0 ||
                        ly1 < e) {
                        switch (p[3] & 0xF0) {
                        case 0x10:
                        case 0x30:
                        case 0x50:
                            p[3] = c + 0x10;
                            break;
                        }
                    }
                }
            }
        }
        p += 8;
    }
}
