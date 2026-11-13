#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
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
        func_800171E8(obj, 0);
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
        func_800171E8(obj, 3);
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
        func_800171E8(obj, 8);
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
            func_800171E8(obj, 0xF);
            *(s16*)(obj + 0x7C) = 0x1C2;
            break;
        case 4 ... 5:
            func_800171E8(obj, 0xB);
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
        func_800171E8(obj, 8);
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
