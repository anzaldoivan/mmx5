#include "types.h"
#include "addr.h"

extern u8 D_8009A1F8[];
extern u8 D_8009A0A0[];
extern s16 D_8009A0AA;
extern s8 D_800D1C44;
extern s16 D_800FD1AC_ovl01[][4];
extern s16 D_800FD204_ovl01[][2];
extern u8 D_800FCF88_ovl01[];
extern s16 D_800FCF90_ovl01[];

extern void func_800F7024_ovl01(s16 x, s16 y, s16 x2, s16 y2, s16 n);
extern s32 func_800F71E8_ovl01(s32, s32);
extern void func_800F6110_ovl01(u8* a0);
extern void func_8001296C(s32);
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
        p = D_8009A0A0;
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
                func_8001296C(3);
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
