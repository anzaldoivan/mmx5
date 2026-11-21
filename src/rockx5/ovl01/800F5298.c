#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"

extern void func_800F6C48_ovl01(u8* a0);
extern void func_800F6DF4_ovl01(u8* arg0);
extern void func_800F6F28_ovl01(u8* arg0, s32 arg1);
extern void func_800F6FA4_ovl01(u8* arg0, s32 arg1);
extern u8 D_8009A0B4;
extern u8 D_800750C0[];
extern u8 D_800FCEF0_ovl01[];
extern u8 D_800FCD88_ovl01[];
extern u8 D_800FCD84_ovl01[];
extern u8 D_800752A0[];
extern s8 D_800D1C00[];
extern u8 D_800FCD80_ovl01[];
extern u16 D_800FD1A0_ovl01[];

void func_800F5298_ovl01(u8* obj) {
    s32 t;
    u8 b;

    obj[0] = 0x41;
    obj[0x5C] = 0x18;
    obj[0x60] = 6;
    obj[0x61] = 0;
    b = D_8009A0B4;
    *(u8**)(obj + 0x58) = D_800750C0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x30) = D_800FCEF0_ovl01;
    obj[0x16] = 5;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 0;
    obj[0x14] = b;
    D_1F80004C.bytes[0x87] = 0;
    D_1F80004C.bytes[0x8A] = 0;

    switch (((s8*)obj)[2] & 0xF0) {
    case 0x30:
        obj[0x5C] = 0x18;
        *(u8**)(obj + 0x54) = D_800FCD88_ovl01;
        *(u8**)(obj + 0x50) = D_800FCD84_ovl01;
        set_animation(obj, 0);
        D_1F80004C.bytes[0x84] = 0;
        D_1F80004C.bytes[0x86] = 1;
        obj[4] = 1;
        obj[5] = 4;
        *(s16*)(obj + 0xA) -= 0x9C;
        *(s16*)(obj + 0xE) += 0x14;
        func_800F6C48_ovl01(obj);
        obj[0x15] = 0;
        break;
    case 0x40:
        set_animation(obj, 3);
        obj[4] = 2;
        obj[5] = 3;
        obj[0x15] = 0;
        *(s16*)(obj + 0xA) -= 0x68;
        *(s16*)(obj + 0xE) += 0x18;
        break;
    case 0:
        *(u8**)(obj + 0x58) = D_800752A0;
        obj[3] = 0;
        obj[0x5C] = 0x1F;
        *(u16*)(D_1F80004C.bytes + 0x88) = *(u16*)(obj + 0x42);
        t = obj[2] & 0xF;
        if ((D_800D1C00[0x26] >> t) & 1) {
            obj[4] = 6;
            return;
        }
        D_800D1C00[0x26] |= 1 << t;
        *(u8**)(obj + 0x54) = D_800FCD80_ovl01;
        *(s32*)(obj + 0x50) = 0;
        set_animation(obj, 8);
        *(s16*)(obj + 0xA) = D_800FD1A0_ovl01[obj[2] & 0xF];
        *(s16*)(obj + 0xE) = 0x158;
        D_1F80004C.bytes[0x87] = 0;
        obj[4] = 3;
        obj[5] = 3;
        obj[0x15] = 0;
        switch (obj[2] & 0xF) {
        case 0:
            *(s32*)(obj + 0x54) = 0;
            func_800F6DF4_ovl01(obj);
            func_800F6F28_ovl01(obj, 0);
            func_800F6F28_ovl01(obj, 1);
            func_800F6F28_ovl01(obj, 8);
            func_800F6F28_ovl01(obj, 0xF);
            func_800F6F28_ovl01(obj, 0x10);
            func_800F6F28_ovl01(obj, 0x11);
            func_800F6F28_ovl01(obj, 0x1E);
            func_800F6F28_ovl01(obj, 0x1F);
            func_800F6F28_ovl01(obj, 0x20);
            break;
        case 1:
            func_800F6DF4_ovl01(obj);
            func_800F6F28_ovl01(obj, 9);
            func_800F6F28_ovl01(obj, 0x12);
            func_800F6F28_ovl01(obj, 0x21);
            break;
        case 2:
            func_800F6DF4_ovl01(obj);
            func_800F6F28_ovl01(obj, 0xA);
            func_800F6F28_ovl01(obj, 0x13);
            func_800F6F28_ovl01(obj, 0x22);
            break;
        case 3:
            func_800F6DF4_ovl01(obj);
            func_800F6F28_ovl01(obj, 2);
            func_800F6F28_ovl01(obj, 3);
            func_800F6F28_ovl01(obj, 0xB);
            func_800F6F28_ovl01(obj, 0x14);
            func_800F6F28_ovl01(obj, 0x15);
            func_800F6F28_ovl01(obj, 0x16);
            func_800F6F28_ovl01(obj, 0x23);
            func_800F6F28_ovl01(obj, 0x24);
            func_800F6F28_ovl01(obj, 0x25);
            func_800F6F28_ovl01(obj, 0x2D);
            func_800F6F28_ovl01(obj, 0x2E);
            func_800F6F28_ovl01(obj, 0x2F);
            func_800F6F28_ovl01(obj, 0x30);
            break;
        case 4:
            func_800F6F28_ovl01(obj, 4);
            func_800F6F28_ovl01(obj, 0xC);
            func_800F6F28_ovl01(obj, 0x17);
            func_800F6F28_ovl01(obj, 0x18);
            func_800F6F28_ovl01(obj, 0x26);
            func_800F6F28_ovl01(obj, 0x27);
            *(s16*)(obj + 0x7E) = 0;
            obj[4] = 5;
            break;
        case 5:
            func_800F6F28_ovl01(obj, 5);
            func_800F6F28_ovl01(obj, 6);
            func_800F6F28_ovl01(obj, 7);
            func_800F6F28_ovl01(obj, 0xD);
            func_800F6F28_ovl01(obj, 0x19);
            func_800F6F28_ovl01(obj, 0x1A);
            func_800F6F28_ovl01(obj, 0x1B);
            func_800F6F28_ovl01(obj, 0x1C);
            func_800F6F28_ovl01(obj, 0x28);
            func_800F6F28_ovl01(obj, 0x29);
            func_800F6F28_ovl01(obj, 0x2A);
            func_800F6F28_ovl01(obj, 0x2B);
            func_800F6FA4_ovl01(obj, 0x31);
            func_800F6FA4_ovl01(obj, 0x32);
            func_800F6FA4_ovl01(obj, 0x33);
            func_800F6FA4_ovl01(obj, 0x34);
            func_800F6FA4_ovl01(obj, 0x35);
            *(s16*)(obj + 0x7E) = 0;
            obj[4] = 5;
            break;
        }
        break;
    case 0x20:
        *(s16*)(obj + 0xA) = 0xF0;
        *(s16*)(obj + 0xE) = 0x30;
        obj[4] = 4;
        obj[5] = 0;
        ((s8*)obj)[0x14] = -1;
        obj[0x15] = 0;
        obj[3] = 0;
        switch (obj[2] & 0xF) {
        case 0 ... 3:
            set_animation(obj, 0xF);
            *(s16*)(obj + 0x7C) = 0x1C2;
            break;
        case 4 ... 5:
            set_animation(obj, 0xB);
            *(s16*)(obj + 0x7C) = 0x32A;
            break;
        }
        break;
    case 0x70:
        obj[4] = 9;
        obj[5] = 0;
        obj[0x15] = 0;
        break;
    case 0x80:
        set_animation(obj, 8);
        obj[4] = 8;
        obj[5] = 0;
        obj[0x15] = 0;
        break;
    }
    *(s16*)(obj + 0x7E) = 0;
    obj[6] = 0;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
}

extern void func_80028A20(s32 a0, s32 a1, s32 a2, s16* a3);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800F6110_ovl01(u8* a0);
extern void func_800F6EE8_ovl01(u8* a0);
extern s32 func_800F71E8_ovl01(s32 a0, s32 a1);
extern u8 D_8009A1F8[];
extern u16 D_8009A202;
extern u8 D_8009A244;
extern s8 D_800D1C44;
extern u8 D_800FCD80_ovl01[];
extern u8 D_800FCF84_ovl01[];
extern void* D_800FD268_ovl01[];

static inline void func_800F58BC_ovl01_spawn(u8* obj, s32 x) {
    s16 buf[4];

    buf[0] = x & 0xFFF0;
    buf[1] = 0x230;
    buf[2] = 0x14;
    buf[3] = 0xC;
    func_80028A20(*(s8*)(obj + 0x14), x & 0xFFF0, 0x130, buf);
}

void func_800F58BC_ovl01(u8* obj) {
    u8* scr;
    u8* g;
    u16 a;
    u16 b;
    u8* d;
    u8* e;

    if (!(obj[2] & 0xF) && *(void**)(obj + 0x54) == 0 &&
        func_800F71E8_ovl01(D_800D1C44, 9) != 0) {
        *(void**)(obj + 0x54) = D_800FCD80_ovl01;
    }
    scr = D_1F80004C.bytes;
    if (scr[0x8A] == 0) {
        d = g_Player;
        if (*(s16*)(d + 0xA) >= *(s16*)(obj + 0xA) - 0x180) {
            scr[0x8A] = 1;
            if ((*(s8*)(obj + 2) & 0xF) < 4) {
                D_8009A1F8[0x47] = 1;
                *(s16*)(D_8009A1F8 + 0x24) = *(u16*)(obj + 0xA) - 0xDC;
            }
        }
    }
    e = g_Player;
    if (e[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        ((void (*)(u8*))D_800FD268_ovl01[*(s8*)(obj + 5)])(obj);
    }
    if (func_80031DD0(obj) < 0) {
        obj[3] = 0;
        func_8004D4F4(4, D_800FCF84_ovl01, obj);
        g = D_8009A1F8;
        g[0x47] = 1;
        *(s16*)(g + 0x24) = 0x2340;
        if ((obj[2] & 0xF) == 2) {
            func_800F6EE8_ovl01(obj);
            *(s16*)(g + 0x2A) = 0x60;
        }
        *(s16*)(obj + 0x7E) = 0;
        obj[4] = 5;
        D_1F80004C.bytes[0x87] = 1;
        func_800F6110_ovl01(obj);
        func_800F58BC_ovl01_spawn(obj, *(u16*)(g + 0xA));
        return;
    }
    b = *(u16*)(D_1F80004C.bytes + 0x88);
    a = *(u16*)(obj + 0x42);
    if ((b ^ a) & 0x8000) {
        if (a & 0x8000) {
            func_800F58BC_ovl01_spawn(obj, D_8009A202);
        } else {
            D_8009A244 = 1;
        }
    }
    *(u16*)(D_1F80004C.bytes + 0x88) = *(u16*)(obj + 0x42);
    func_8002D9EC(obj, 0x40, 0x20);
}

extern u8 D_8009A1F8[];
extern s8 D_800D1C44;
extern s16 D_800FD1AC_ovl01[][4];
extern s16 D_800FD204_ovl01[][2];
extern u8 D_800FCF88_ovl01[];
extern s16 D_800FCF90_ovl01[];

extern void func_800F7024_ovl01(s16 x, s16 y, s16 x2, s16 y2, s16 n);
extern s32 func_800F71E8_ovl01(s32, s32);
extern void func_800F6110_ovl01(u8* a0);
extern void start_pad_vibration(s32);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80028C10(s32, s32, s32, void*);

void func_800F5B38_ovl01(u8* o) {
    u8* d;
    u8* q;
    u8* r;
    u8* p;
    s16 camr;
    s32 cam;
    s32 x0, x1;
    s32 idx;
    s32 left, right, top, bottom;

    d = D_8009A1F8;
    cam = *(s16*)(d + 0xA);
    camr = *(u16*)(d + 0xA) + 0x140;
    x1 = D_800FD1AC_ovl01[o[2] & 0xF][1];
    x0 = D_800FD1AC_ovl01[o[2] & 0xF][0];
    if (cam >= x1 || x0 >= camr) {
        left = x0;
        right = x1;
    } else {
        if (x0 < cam) {
            left = cam;
        } else {
            left = x0;
        }
        if (camr < x1) {
            right = camr;
        } else {
            right = x1;
        }
    }
    top = D_800FD1AC_ovl01[o[2] & 0xF][2];
    bottom = D_800FD1AC_ovl01[o[2] & 0xF][3];
    idx = o[2] & 0xF;

    if (((s8*)o)[7] == 0) {
        if (idx < 4) {
            *(u16*)(o + 0x42) &= 0x7FFF;
            q = D_8009A1F8;
            q[0x4C] = 1;
            o[7]++;
            return;
        }
        if (((*(u16*)(o + 0x7C))++ & 0xF) == 0) {
            func_800F7024_ovl01(left, top, right, bottom, 2);
        }
        p = g_Player;
        if (left - 0x20 < *(s16*)(p + 0xA) && *(s16*)(p + 0xA) < right + 0x20) {
            if (*(s16*)(p + 0xA) != *(s16*)(p + 0x1A) ||
                *(s16*)(o + 0x7E) == 1) {
                *(s16*)(o + 0x7E) = 1;
                if ((o[2] & 0xF) == 4) {
                    if (func_800F71E8_ovl01(D_800D1C44, 10) == 0) {
                        return;
                    }
                    if ((p[0x70] & 0xF) == 0) {
                        return;
                    }
                    D_1F80004C.bytes[0x87] = 1;
                    func_800F6110_ovl01(o);
                    o[7]++;
                } else if ((p[0x70] & 0xF) != 0) {
                    D_1F80004C.bytes[0x87] = 1;
                    func_800F6110_ovl01(o);
                    o[7]++;
                }
            }
        }
    } else if (((s8*)o)[7] == 1) {
        if (((*(u16*)(o + 0x7C))++ & 7) == 0) {
            if (D_8009A0AA < right) {
                func_800F7024_ovl01(left, top, right, bottom, 2);
            } else {
                func_800F7024_ovl01(left, top, right, bottom, 1);
            }
        }
        if (D_1F80004C.bytes[0x87] == 2) {
            if (D_800FD204_ovl01[o[2] & 0xF][0] <= D_8009A0AA &&
                D_8009A0AA <= D_800FD204_ovl01[o[2] & 0xF][1]) {
                start_pad_vibration(3);
            }
            o[3] = 0;
            *(s16*)(o + 0xA) -= 0x40;
            *(s16*)(o + 0xE) += 0x30;
            func_8004D4F4(9, D_800FCF88_ovl01, o);
            func_800F7024_ovl01(left, top, right, bottom, 0x20);
            o[7]++;
        }
    } else if (((s8*)o)[7] == 2) {
        o[3] = 0;
        switch (idx) {
        case 0:
            func_80028C10(((s8*)o)[0x14], D_800FCF90_ovl01[0],
                          D_800FCF90_ovl01[1], &D_800FCF90_ovl01[2]);
            break;
        case 1:
            func_80028C10(((s8*)o)[0x14], D_800FCF90_ovl01[6],
                          D_800FCF90_ovl01[7], &D_800FCF90_ovl01[8]);
            break;
        case 2:
            func_80028C10(((s8*)o)[0x14], D_800FCF90_ovl01[12],
                          D_800FCF90_ovl01[13], &D_800FCF90_ovl01[14]);
            break;
        case 3:
            func_80028C10(((s8*)o)[0x14], D_800FCF90_ovl01[30],
                          D_800FCF90_ovl01[31], &D_800FCF90_ovl01[32]);
            break;
        case 4:
            func_80028C10(((s8*)o)[0x14], D_800FCF90_ovl01[36],
                          D_800FCF90_ovl01[37], &D_800FCF90_ovl01[38]);
            break;
        case 5:
            func_80028C10(((s8*)o)[0x14], D_800FCF90_ovl01[42],
                          D_800FCF90_ovl01[43], &D_800FCF90_ovl01[44]);
            break;
        }
        r = D_8009A1F8;
        r[0x4C] = 1;
        D_1F80004C.bytes[0x87] = 3;
        *(u16*)(o + 0x7C) = 0x5F;
        o[7]++;
    } else if (((s8*)o)[7] == 3) {
        o[3] = 0;
        if (--*(s16*)(o + 0x7C) == 0) {
            o[4] = 6;
        }
    }
}
