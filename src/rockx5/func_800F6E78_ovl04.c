#include "types.h"

typedef struct Ob6E78 {
    /* 0x00 */ u8 x0;
    /* 0x01 */ u8 x1;
    /* 0x02 */ signed char x2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 x4;
    /* 0x05 */ u8 x5;
    /* 0x06 */ u8 x6;
    /* 0x07 */ u8 pad7[0xE - 0x7];
    /* 0x0E */ u16 xE;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u8 x14;
    /* 0x15 */ u8 x15;
    /* 0x16 */ u8 x16;
    /* 0x17 */ u8 pad17[0x24 - 0x17];
    /* 0x24 */ s32 x24;
    /* 0x28 */ u8 pad28[0x50 - 0x28];
    /* 0x50 */ void* x50;
    /* 0x54 */ void* x54;
    /* 0x58 */ void* x58;
    /* 0x5C */ u8 pad5C[0x60 - 0x5C];
    /* 0x60 */ u8 x60;
    /* 0x61 */ u8 x61;
    /* 0x62 */ u8 pad62[0x65 - 0x62];
    /* 0x65 */ u8 x65;
    /* 0x66 */ u8 x66;
    /* 0x67 */ u8 pad67;
    /* 0x68 */ void* x68;
    /* 0x6C */ u8 pad6C[0x75 - 0x6C];
    /* 0x75 */ u8 x75;
    /* 0x76 */ u8 pad76[0x7C - 0x76];
    /* 0x7C */ void* x7C; /* an Ob6E78 */
    /* 0x80 */ u8 pad80[0x82 - 0x80];
    /* 0x82 */ u8 x82;
    /* 0x83 */ u8 x83;
    /* 0x84 */ u8 pad84[0x90 - 0x84];
    /* 0x90 */ signed char x90;
    /* 0x91 */ u8 pad91[0xA2 - 0x91];
    /* 0xA2 */ u8 xA2;
} Ob6E78;

typedef struct {
    u16 h;
    u16 pad;
    s32 v;
} Ent6E78;

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
