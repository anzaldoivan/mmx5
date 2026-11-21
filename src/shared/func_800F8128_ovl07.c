#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/object.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

extern s32 func_8002B5B4(s32);
extern u8 D_80076CE0[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800C6A10[];
extern signed char D_800D1C0C;
extern Blk4 D_801016D0_ovl07;
extern u8 D_801016D4_ovl07[];

void func_800F8128_ovl07(u8* p) {
    s32 r;

    p[4] = 1;
    p[5] = 2;
    p[6] = 2;
    p[0] = 0x41;
    p[0x15] = 0;
    p[0x14] = D_8009A0B4;
    *(s16*)(p + 0x40) = D_80098118[func_8002B5B4(0x98)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x98)];
    r = func_8002B5B4(0x98);
    *(s16*)(p + 0x42) =
        ((r * 4 + 0x18) % 16) | (((func_8002B5B4(0x98) + 6) / 4 + 0x1E0) << 6);
    if (D_800D1C0C == 7) {
        p[0x16] = 0x20;
    } else {
        p[0x16] = 0x37;
    }
    p[0x47] = 0;
    p[0x5C] = 8;
    *(u8**)(p + 0x58) = D_80076CE0;
    *(u8**)(p + 0x68) = p + 0x80;
    *(Blk4*)(p + 0x80) = D_801016D0_ovl07;
    *(u8**)(p + 0x54) = D_801016D4_ovl07;
    *(s32*)(p + 0x50) = 0;
    p[0x61] = 0;
    p[0x75] = 1;
    p[0x60] = 0x10;
    p[0x65] = 0;
    p[0xA2] = 1;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    p[0x85] = 0;
    if (func_800F7FF4_ovl07(p, *(s16*)(p + 0xA), *(s16*)(p + 0xE)) != 0) {
        p[4] = 2;
    }
    if (((s8*)p)[2] == 0x11) {
        Blk0A4* d = (Blk0A4*)D_800C6A10;
        d[63] = *(Blk0A4*)p;
        clear_object_slot(p);
    }
}

extern s32 func_80032F70(u8* a0);
extern int func_8002D7A0();
extern void func_8003258C(u8* a0);
extern s32 func_800326BC(u8* a0);
extern s8 D_800D1C00[];
extern void* D_801016E4_ovl07[];

void func_800F8330_ovl07(u8* arg0) {
    s16 y;
    s16 cmp;
    s16 val;

    if (D_800D1C00[0xC] == 7) {
        y = *(s16*)(arg0 + 0xE);
        if (y >= 0x468) {
            arg0[0x16] = 0x23;
        } else if (y >= 0x458) {
            arg0[0x16] = 0x22;
        } else if (y >= 0x428) {
            arg0[0x16] = 0x21;
        } else {
            arg0[0x16] = 0x20;
        }
    } else {
        y = *(s16*)(arg0 + 0xE);
        if (y >= 0x4F8) {
            arg0[0x16] = 0x37;
        } else if (y >= 0x4C8) {
            arg0[0x16] = 0x36;
        } else if (y >= 0x498) {
            arg0[0x16] = 0x35;
        } else if (y >= 0x468) {
            arg0[0x16] = 0x34;
        } else if (y >= 0x438) {
            arg0[0x16] = 0x33;
        } else if (y >= 0x408) {
            arg0[0x16] = 0x32;
        }
    }
    ((void (*)())func_80033024)(arg0);
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    ((void (*)(u8*))D_801016E4_ovl07[(s8)arg0[6]])(arg0);
    if ((s8)func_80032F70(arg0) < 0) {
        ((s32(*)())func_8004FD90)(arg0, 1, 0x1F, 0xF);
        arg0[4] = 2;
        return;
    }
    if (is_off_screen(arg0, 0x80, 0x80) == 0) {
        func_8002D89C(arg0);
    } else {
        val = D_800D1C00[0xC];
        if (val == 7) {
            cmp = 1;
            val = D_800D1C00[0x1D];
        } else {
            cmp = 0x1ED8;
            val = *(s16*)(arg0 + 0xA);
        }
        if (val != cmp) {
            func_8002D7A0(arg0);
        }
    }
    func_8003258C(arg0);
    func_800326BC(arg0);
    if (arg0[0x70] & 8) {
        arg0[0x67] = 0;
        return;
    }
    if (*(s32*)(arg0 + 0x24) < 0) {
        *(s8*)(arg0 + 0x67) = -1;
    } else {
        arg0[0x67] = 1;
    }
}

extern s32 func_8003240C(u8* a0);

void func_800F851C_ovl07(u8* o) {
    s32 r1;
    s32 r2;
    s32 r3;
    s32 r4;
    s32 r5;
    s32 r6;
    s32 v;
    s32 d;
    s16 x;
    u8* p;
    s32 k;

    x = *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80));
    r1 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, x - 1, *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    x = (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82);
    r2 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, x + 1, *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    r3 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)),
        *(u16*)(o + 0xE) + 0x10);
    x = (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82);
    r4 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(o, x - 1,
                                                      *(u16*)(o + 0xE) + 0x10);
    r5 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)),
        *(s16*)(o + 0xE));
    x = (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82);
    r6 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(o, x - 1,
                                                      *(s16*)(o + 0xE));
    v = *(s32*)(o + 0x20);
    if ((v > 0 && (r3 != 0 || (*(u8*)(o + 0x70) & 1))) ||
        (v < 0 && (r4 != 0 || (*(u8*)(o + 0x70) & 2))) ||
        (v > 0 && (r5 != 0 || (*(u8*)(o + 0x70) & 1))) ||
        (v < 0 && (r6 != 0 || (*(u8*)(o + 0x70) & 2)))) {
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(u8*)(o + 0x6) = 2;
        *(u16*)(o + 0xA) = (*(u16*)(o + 0xA) & 0xFFF0) | 8;
        return;
    }
    apply_object_motion(o);
    func_8002FB58(o);
    if (r1 == 0 && r2 == 0 && !(*(u8*)(o + 0x70) & 8)) {
        k = 0x1000;
        v = *(u16*)(o + 0xA);
        *(s32*)(o + 0x2C) = k;
        *(s16*)(o + 0x8) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        k = 1;
        *(u8*)(o + 0x6) = k;
        *(u8*)(o + 0x85) = 0;
        v &= 0xFFF0;
        v |= 8;
        *(u16*)(o + 0xA) = v;
        return;
    }
    d = *(s16*)(o + 0x7C) - *(s16*)(o + 0xA);
    if (!(d >= 0 ? d < 0x30 : *(s16*)(o + 0xA) - *(s16*)(o + 0x7C) < 0x30)) {
        if (*(s32*)(o + 0x20) > 0) {
            *(u16*)(o + 0xA) = *(u16*)(o + 0x7C) + 0x30;
        } else {
            *(u16*)(o + 0xA) = *(u16*)(o + 0x7C) - 0x30;
        }
        *(s16*)(o + 0x8) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
        *(u8*)(o + 0x6) = 2;
    }
    p = g_Player;
    if (p[0xF8] == 0) {
        d = *(s16*)(p + 0xA) - *(s16*)(o + 0xA);
        if (d >= 0 ? d < 0x30 : *(s16*)(o + 0xA) - *(s16*)(p + 0xA) < 0x30) {
            func_8003240C(o);
        }
    }
}

extern s32 func_8002A5C4(s32, s32, s32);
extern s32 func_8003240C(u8* a0);

void func_800F88F0_ovl07(u8* o) {
    s32 r1;
    s32 r2;
    u8* p;
    s32 d;
    s16 x;

    x = *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80));
    r1 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, x - 1, *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    r2 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82),
        *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    if ((*(u8*)(o + 0x70) & 8) || r1 != 0 || r2 != 0) {
        *(s16*)(o + 0xC) = 0;
        *(u16*)(o + 0xE) = (*(u16*)(o + 0xE) & 0xFFF0) | 8;
        play_sound(5, 0x26, 0);
        if (*(u8*)(o + 0x85) >= 0x11) {
            func_8002A5C4(0x10, 2, 1);
        }
        *(s16*)(o + 0x8) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
        *(u8*)(o + 0x6) = 2;
    }
    if (*(s32*)(o + 0x24) <= -0x20000) {
        *(s32*)(o + 0x24) = -0x20000;
    }
    apply_object_motion(o);
    p = g_Player;
    *(u8*)(o + 0x85) += 1;
    if (p[0xF8] == 0) {
        d = *(s16*)(p + 0xA) - *(s16*)(o + 0xA);
        if (d >= 0 ? d < 0x30 : *(s16*)(o + 0xA) - *(s16*)(p + 0xA) < 0x30) {
            func_8003240C(o);
        }
    }
    func_8002FB58(o);
}

extern s32 func_8003240C(u8* a0);

void func_800F8AD0_ovl07(u8* o) {
    u8* g;
    // !FAKE: register pin keeps the second result in v0
    register s32 r2 asm("$2");
    s32 r1;
    s16 x;

    func_8002FB58(o);
    x = *(s16*)(o + 0xA) + (s8)o[0x80] + o[0x82];
    r1 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, x - 1, *(s16*)(o + 0xE) + (s8)o[0x81] + o[0x83]);
    r2 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, *(s16*)(o + 0xA) + (s8)o[0x80] - o[0x82],
        *(s16*)(o + 0xE) + (s8)o[0x81] + o[0x83]);
    g = g_Player;
    if (!(o[0x70] & 8) && r1 == 0 && r2 == 0) {
        *(s32*)(o + 0x2C) = 0x1000;
        o[6] = 1;
        o[0x85] = 0;
    } else {
        o[0x84] = g[0x71];
        if (g_Player[0xF8] == 0) {
            if (((*(s16*)(g_Player + 0xA) - *(s16*)(o + 0xA)) < 0
                     ? (*(s16*)(o + 0xA) - *(s16*)(g_Player + 0xA))
                     : (*(s16*)(g_Player + 0xA) - *(s16*)(o + 0xA))) < 0x30) {
                func_8003240C(o);
            }
        }
        o[0x84] ^= g[0x71];
        if ((*(s32*)(g + 4) & 0xFFFF00) == 0x10C00 && g[0xFA] == 3) {
            if ((o[0x84] & 2) && g[0x15] == 0) {
                *(s32*)(o + 0x20) = -0x40000;
                *(s32*)(o + 0x28) = -0x2400;
            } else {
                if (!(o[0x84] & 1) || g[0x15] != 0x40) {
                    return;
                }
                *(s32*)(o + 0x20) = 0x40000;
                *(s32*)(o + 0x28) = 0x2400;
            }
            *(s32*)(o + 0x24) = 0;
            *(s32*)(o + 0x2C) = 0;
            o[6] = 0;
            *(s16*)(o + 0x7C) = *(s16*)(o + 0xA);
        }
    }
}
