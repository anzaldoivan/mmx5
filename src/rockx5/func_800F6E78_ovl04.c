#include "types.h"

extern void func_800171E8(Ob6E78*, s32);
extern Ob6E78* func_8002D1A4();
extern u8 D_8009A0A0[];
extern u8 D_80101D4C_ovl04[];
extern u8 D_800767E0[];
extern Ent6E78 D_80101D60_ovl04[][37];
extern signed char D_800D1C0C;
extern u8 D_80101D50_ovl04[];
extern u8 D_80101D54_ovl04[];
extern u8 D_80101D5C_ovl04[];

void func_800F6E78_ovl04(Ob6E78* o) {
    Ob6E78* p;
    u8 s;

    o->x4 = 1;
    o->x5 = 2;
    o->x24 = 0;
    o->x0 = 0x41;
    o->xA2 = 1;
    o->x14 = D_8009A0A0[0x14];
    o->x54 = D_80101D4C_ovl04;
    o->x50 = 0;
    o->x16 = 5;
    o->x61 = 0;
    o->x60 = 6;
    o->x75 = 1;
    o->x83 = 0;
    o->x65 = 0;
    o->x58 = D_800767E0;
    if (o->x2 >= 100) {
        o->x15 = 0x40;
        func_800171E8(o, 0x18);
        o->x66 = 0;
        o->x6 = 3;
        return;
    }
    o->x15 = 0;
    if (((Ob6E78*)o->x7C)->x90 > 0) {
        func_800171E8(o, 0x12);
        o->x68 = &D_80101D60_ovl04[o->x82][o->x2].v;
        if (D_800D1C0C != 12) {
            o->xE = D_80101D60_ovl04[o->x82][o->x2].h;
        } else {
            o->xE = D_80101D60_ovl04[o->x82][o->x2].h + 16;
        }
        o->x6 = 1;
        if (o->x82 == 4) {
            switch (o->x2) {
            case 2:
            case 5:
            case 8:
                func_800171E8(o, 0x14);
                o->x60 = 0x7F;
                o->x50 = D_80101D50_ovl04;
                if (D_8009A0A0[0xFA] == 3) {
                    o->x60 = 6;
                    o->x68 = D_80101D54_ovl04;
                } else {
                    o->x60 = 0x7F;
                    o->x68 = 0;
                }
                s = D_8009A0A0[0xFA];
                if (s == 2) {
                    o->x50 = 0;
                    p = func_8002D1A4();
                    if (p != 0) {
                        p->x0 = 0x41;
                        p->x1 = 0x22;
                        p->x2 = s;
                        p->x7C = o;
                    }
                }
                break;
            }
        }
        if (o->x82 == 6) {
            switch (o->x2) {
            case 14:
            case 17:
            case 20:
            case 28:
            case 30:
                func_800171E8(o, 0x14);
                o->x60 = 0x7F;
                o->x50 = D_80101D50_ovl04;
                if (D_8009A0A0[0xFA] == 3) {
                    o->x60 = 6;
                    o->x68 = D_80101D54_ovl04;
                    if (o->x2 == 30) {
                        o->x68 = D_80101D5C_ovl04;
                    }
                    if (o->x2 == 28) {
                        o->x68 = 0;
                    }
                } else {
                    o->x60 = 0x7F;
                    o->x68 = 0;
                }
                s = D_8009A0A0[0xFA];
                if (s == 2) {
                    o->x50 = 0;
                    p = func_8002D1A4();
                    if (p != 0) {
                        p->x0 = 0x41;
                        p->x1 = 0x22;
                        p->x2 = s;
                        p->x7C = o;
                    }
                }
                break;
            }
        }
        if (o->x82 == 7) {
            switch (o->x2) {
            case 2:
            case 5:
            case 8:
            case 26:
            case 28:
                func_800171E8(o, 0x14);
                o->x50 = D_80101D50_ovl04;
                if (D_8009A0A0[0xFA] == 3) {
                    o->x60 = 6;
                    o->x68 = D_80101D54_ovl04;
                    if (o->x2 == 28) {
                        o->x68 = D_80101D5C_ovl04;
                    }
                    if (o->x2 == 26) {
                        o->x68 = 0;
                    }
                } else {
                    o->x60 = 0x7F;
                    o->x68 = 0;
                }
                s = D_8009A0A0[0xFA];
                if (s == 2) {
                    o->x50 = 0;
                    p = func_8002D1A4();
                    if (p != 0) {
                        p->x0 = 0x41;
                        p->x1 = 0x22;
                        p->x2 = s;
                        p->x7C = o;
                    }
                }
                break;
            }
        }
    } else {
        func_800171E8(o, 0x16);
        o->x68 = &D_80101D60_ovl04[o->x82][o->x2].v;
        if (D_800D1C0C != 12) {
            o->xE = D_80101D60_ovl04[o->x82][o->x2].h;
        } else {
            o->xE = D_80101D60_ovl04[o->x82][o->x2].h + 16;
        }
        o->x6 = 0;
    }
}
