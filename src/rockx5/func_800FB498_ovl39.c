#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A0A0[];
extern u8 D_80074E40[];
extern u8 D_800FECCC_ovl39[];
extern u8 D_800FECD0_ovl39[];
extern u8 D_800FECD8_ovl39[];
extern u8 D_800FECDC_ovl39[];
extern u8 D_800FECE0_ovl39[];
extern u8 D_800FECE4_ovl39[];
extern u8 D_800FECEC_ovl39[];
extern u8 D_800FECF0_ovl39[];
extern s16 D_800FECF4_ovl39[];

void func_800FB498_ovl39(u8* obj) {
    u8* p;
    s32 i;
    s32 ang;
    s16 v;
    s8 b;
    u8* d;
    u8* d1;
    u8* d2;
    s32 st;

    obj[3] = 1;
    obj[0x16] = 1;
    d = D_8009A0A0;
    st = (s8)obj[2];
    obj[0x14] = d[0x14];
    switch (st) {
    case 0:
        *(u8**)(obj + 0x50) = D_800FECCC_ovl39;
        *(u8**)(obj + 0x54) = D_800FECCC_ovl39;
        *(u8**)(obj + 0x68) = D_800FECD0_ovl39;
        *(u8**)(obj + 0x58) = D_80074E40;
        obj[0x60] = 8;
        if (obj[0x15] == 0) {
            *(s32*)(obj + 0x20) = 0xFFF60000;
        } else {
            *(s32*)(obj + 0x20) = 0xA0000;
        }
        *(s32*)(obj + 0x24) = 0;
        func_800171E8(obj, 9);
        obj[5] = 0;
        func_80016490(2, 0xA6, obj);
        break;
    case 1:
        for (i = 0; i < 2; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 0x28;
                p[2] = i + 0xB;
                *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
                *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                *(s32*)(p + 0x7C) = *(s32*)(obj + 0x7C);
            }
        }
        func_80016490(2, 0xA7, obj);
    case 11:
    case 12:
        obj[0x16] = 4;
        *(s16*)(obj + 0xE) = 0x824;
        obj[0x60] = 0xC;
        *(s32*)(obj + 0x68) = 0;
        *(s32*)(obj + 0x54) = 0;
        if ((s8)obj[2] == 1) {
            *(s16*)(obj + 0x90) = -4;
            obj[0x15] = 0;
            *(u8**)(obj + 0x50) = D_800FECDC_ovl39;
            func_800171E8(obj, 0xF);
        } else if ((s8)obj[2] == 0xC) {
            *(s16*)(obj + 0x90) = -0x28;
            obj[0x15] = 0;
            *(u8**)(obj + 0x50) = D_800FECD8_ovl39;
            func_800171E8(obj, 0xE);
        } else {
            *(s16*)(obj + 0x90) = 0x18;
            obj[0x15] = 0x40;
            *(u8**)(obj + 0x50) = D_800FECE0_ovl39;
            func_800171E8(obj, 0xE);
        }
        obj[5] = 1;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        ang = ratan2(0x830 - *(s16*)(obj + 0xE),
                     D_800FECF4_ovl39[(s8)obj[2] - 2] - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(ang) * 0x60;
        *(s32*)(obj + 0x24) = -rsin(ang) * 0x60;
        *(u8**)(obj + 0x50) = D_800FECE4_ovl39;
        *(u8**)(obj + 0x68) = D_800FECEC_ovl39;
        *(u8**)(obj + 0x58) = D_80074E40;
        *(s32*)(obj + 0x54) = 0;
        obj[0x60] = 8;
        func_800171E8(obj, 0x11);
        obj[5] = 3;
        func_80016490(2, 0xA8, obj);
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        obj[0x15] = 0;
        obj[0x16] = 5;
        d1 = D_8009A0A0;
        v = *(s16*)(d1 + 0xA);
        if (v > 0x1240) {
            *(s16*)(obj + 0xA) = 0x1268;
        } else if (v >= 0x11E0) {
            *(s16*)(obj + 0xA) = 0x1218;
        } else {
            *(s16*)(obj + 0xA) = 0x11B8;
        }
        d2 = D_8009A0A0;
        if (*(s16*)(d2 + 0xE) < 0x7F0) {
            *(s16*)(obj + 0xE) = 0x7B8;
        } else {
            b = d2[5];
            if (b == 0xC || b == 0x1A || b == 0x3C) {
                *(s16*)(obj + 0xE) = 0x7EC;
            } else {
                *(s16*)(obj + 0xE) = 0x808;
            }
        }
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x68) = 0;
        *(u8**)(obj + 0x58) = D_80074E40;
        obj[0x60] = 0x14;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        func_800171E8(obj, 0x10);
        obj[5] = 9;
        func_80016490(2, 0xA9, obj);
        break;
    case 13:
        obj[0x60] = 8;
        obj[0x16] = 5;
        *(u8**)(obj + 0x50) = D_800FECF0_ovl39;
        obj[0x47] = 0x46;
        obj[5] = 0xD;
        obj[3] = 0;
        break;
    }
    obj[4]++;
}
