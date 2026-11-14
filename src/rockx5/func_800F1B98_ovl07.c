#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8* func_8002D210();
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0B4;
extern u32* D_80098118;
extern u8 D_80100F60_ovl07[];
extern u8 D_8010101C_ovl07[];
extern u8 D_80074EE0[];

static inline void func_800F1B98_ovl07_slot(u8* obj, s32 off) {
    s32 a;
    s32 b;

    a = func_8002B5B4(0x87);
    b = func_8002B5B4(0x87);
    *(u16*)(obj + 0x42) = ((a * 4 + off) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
}

void func_800F1B98_ovl07(u8* obj) {
    s32 r;
    u8* p;
    s32 hi;

    obj[0] = 0x41;
    obj[4]++;
    obj[0x14] = D_8009A0B4;
    r = func_8002B5B4(0x87);
    *(u16*)(obj + 0x40) = D_80098118[r] >> 7;
    r = func_8002B5B4(0x87);
    *(s32*)(obj + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[r];
    func_800F1B98_ovl07_slot(obj, 0x18);
    obj[0x16] = 6;
    obj[0x47] = 0x11;
    obj[0x5C] = 0;
    obj[0x61] = 0;
    *(u8**)(obj + 0x30) = D_80100F60_ovl07;
    obj[0x76] = 0;
    hi = obj[2] >> 4;
    if (hi != 0) {
        *(u8**)(obj + 0x54) = D_8010101C_ovl07;
        *(u8**)(obj + 0x58) = D_80074EE0;
        obj[0x60] = 4;
        obj[0x65] = 0;
        *(u8**)(obj + 0x50) = obj + 0x8C;
        obj[5] = 6;
        obj[6] = 0;
        obj[0x86] = 0;
        obj[0x87] = 0;
        switch (hi) {
        case 1:
            *(u16*)(obj + 0xA) = 0x1E78;
            *(u16*)(obj + 0xE) = 0x250;
            break;
        case 2:
            *(u16*)(obj + 0xA) = 0x1BC8;
            *(u16*)(obj + 0xE) = 0x240;
            break;
        case 3:
            *(u16*)(obj + 0xA) = 0x1978;
            *(u16*)(obj + 0xE) = 0x288;
            break;
        case 4:
            *(u16*)(obj + 0xA) = 0x19B8;
            *(u16*)(obj + 0xE) = 0x220;
            func_800F1B98_ovl07_slot(obj, 0x19);
            break;
        case 5:
            *(u16*)(obj + 0xA) = 0x19C8;
            *(u16*)(obj + 0xE) = 0x480;
            obj[0x86] = 1;
            break;
        case 6:
            *(u16*)(obj + 0xA) = 0x19A8;
            *(u16*)(obj + 0xE) = 0x410;
            func_800F1B98_ovl07_slot(obj, 0x19);
            obj[0x86] = 1;
            break;
        case 7:
            *(u16*)(obj + 0xA) = 0x1C28;
            *(u16*)(obj + 0xE) = 0x548;
            obj[0x86] = 1;
            break;
        case 8:
            *(u16*)(obj + 0xA) = 0x1BF8;
            *(u16*)(obj + 0xE) = 0x4F0;
            func_800F1B98_ovl07_slot(obj, 0x19);
            break;
        case 9:
            *(u16*)(obj + 0xA) = 0x1E30;
            *(u16*)(obj + 0xE) = 0x510;
            obj[0x87] = 1;
            break;
        case 10:
            *(u16*)(obj + 0xA) = 0x2008;
            *(u16*)(obj + 0xE) = 0x560;
            obj[0x86] = 1;
            break;
        case 11:
            *(u16*)(obj + 0xA) = 0x1F90;
            *(u16*)(obj + 0xE) = 0x510;
            func_800F1B98_ovl07_slot(obj, 0x19);
            break;
        case 12:
            *(u16*)(obj + 0xA) = 0x1FC8;
            *(u16*)(obj + 0xE) = 0x410;
            obj[0x87] = 1;
            break;
        }
        obj[0x83] = 0;
        obj[0x84] = 0;
        *(u16*)(obj + 0x88) = 0;
        *(u16*)(obj + 0xA0) = 0;
        obj[0x82] = 0;
        obj[0x85] = 0;
        *(u16*)(obj + 0x7C) = *(u16*)(obj + 0xA);
        *(u16*)(obj + 0x7E) = *(u16*)(obj + 0xE);
        p = func_8002D210();
        if (p != 0) {
            p[0x60] = 6;
            p[0] = 0x41;
            p[1] = 5;
            p[2] = obj[2] >> 4;
            *(u8**)(p + 0x7C) = obj;
        }
        if (obj[2] & 0xF) {
            obj[2] = 1;
        } else {
            obj[2] = 0;
        }
        if (((s8*)obj)[2] != 0) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0x4000;
            obj[0x81] = 3;
            func_800171E8(obj, 3);
            return;
        }
        if (obj[0x86] != 0) {
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = 0x4000;
        } else {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = -0x4000;
        }
        *(s32*)(obj + 0x24) = 0;
        obj[0x81] = 4;
        func_800171E8(obj, 8);
        return;
    }
    obj[0x16] = 7;
    switch (obj[2] & 0xF) {
    case 1:
        *(u16*)(obj + 0xA) = 0x1E10;
        *(u16*)(obj + 0xE) = 0x280;
        ((s8*)obj)[0x66] = 1;
        break;
    case 2:
        *(u16*)(obj + 0xA) = 0x1B90;
        *(u16*)(obj + 0xE) = 0x280;
        ((s8*)obj)[0x66] = 1;
        break;
    case 3:
        *(u16*)(obj + 0xA) = 0x1940;
        *(u16*)(obj + 0xE) = 0x2A0;
        ((s8*)obj)[0x66] = -2;
        break;
    case 4:
        *(u16*)(obj + 0xA) = 0x1940;
        *(u16*)(obj + 0xE) = 0x2C0;
        ((s8*)obj)[0x66] = -1;
        func_800F1B98_ovl07_slot(obj, 0x19);
        break;
    case 5:
        *(u16*)(obj + 0xA) = 0x1A10;
        *(u16*)(obj + 0xE) = 0x3E0;
        ((s8*)obj)[0x66] = 2;
        break;
    case 6:
        *(u16*)(obj + 0xA) = 0x1A30;
        *(u16*)(obj + 0xE) = 0x3E0;
        ((s8*)obj)[0x66] = 3;
        func_800F1B98_ovl07_slot(obj, 0x19);
        break;
    case 7:
        *(u16*)(obj + 0xA) = 0x1CB0;
        *(u16*)(obj + 0xE) = 0x4F0;
        ((s8*)obj)[0x66] = 3;
        break;
    case 8:
        *(u16*)(obj + 0xA) = 0x1C90;
        *(u16*)(obj + 0xE) = 0x4F0;
        ((s8*)obj)[0x66] = 2;
        func_800F1B98_ovl07_slot(obj, 0x19);
        break;
    case 9:
        *(u16*)(obj + 0xA) = 0x1E60;
        *(u16*)(obj + 0xE) = 0x4C0;
        ((s8*)obj)[0x66] = -1;
        break;
    case 10:
        *(u16*)(obj + 0xA) = 0x2020;
        *(u16*)(obj + 0xE) = 0x530;
        ((s8*)obj)[0x66] = -3;
        break;
    case 11:
        *(u16*)(obj + 0xA) = 0x2020;
        *(u16*)(obj + 0xE) = 0x510;
        ((s8*)obj)[0x66] = -1;
        func_800F1B98_ovl07_slot(obj, 0x19);
        break;
    case 12:
        *(u16*)(obj + 0xA) = 0x1FF0;
        *(u16*)(obj + 0xE) = 0x460;
        ((s8*)obj)[0x66] = 1;
        break;
    }
    obj[5] = 5;
    obj[6] = 0;
    obj[0x75] = 1;
    obj[0x76] = 0;
    obj[0xA2] = 1;
}
