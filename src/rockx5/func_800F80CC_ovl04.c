#include "types.h"
#include "addr.h"

extern u8* func_8002CA10(u8* obj, s32 arg1);
extern u8* func_8002D27C(void);
extern u8* func_8002D210();
extern void func_80016490(s32, s32, void*);
extern void func_8001296C(s32);
extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u16 D_80103090_ovl04;
extern u16 D_80103092_ovl04;
extern u8 D_8009A29E;
extern s8 D_800D1C2C;
extern u8 D_800D1C00[];
extern u8 D_80076920[];
extern u8 D_80102A78_ovl04[];
extern u8 D_8010295C_ovl04[];
extern u8 D_80102A7C_ovl04[];
extern u8 D_80102A80_ovl04[];
extern u32* D_80098118;
extern u8 D_800755C0[];
extern u8 D_80102A84_ovl04[];
extern u8 D_80102A88_ovl04[];
extern u8 D_80102A8C_ovl04[];
extern u8 D_80102A90_ovl04[];
extern u8 D_800750C0[];
extern u8 D_80102A94_ovl04[];
extern u8 D_80102A98_ovl04[];
extern u8 D_8009A1F8[];
extern u8 D_80102AA4_ovl04[];
extern u8 D_80102AA8_ovl04[];
extern u8 D_80102AAC_ovl04[];
extern u8 D_80102AB0_ovl04[];
extern u8 D_80102AB4_ovl04[];
extern u8 D_80102AB8_ovl04[];
extern u8 D_80102ABC_ovl04[];
extern u8 D_80102AC0_ovl04[];
extern u8 D_80102AC4_ovl04[];
extern u8 D_80102AC8_ovl04[];
extern u8 D_80102ACC_ovl04[];

static inline void func_800F80CC_ovl04_spawn(u8* obj, s32 n) {
    u8* p = func_8002CA10(obj, 0);
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x1E;
        p[2] = n;
        *(u8**)(p + 0x80) = obj;
    }
}

static inline void func_800F80CC_ovl04_spawn2(u8* obj) {
    u8* p = func_8002D210();
    if (p != 0) {
        *(u8**)(p + 0x7C) = obj;
        p[1] = 9;
        p[2] = obj[2];
        p[0] = 1;
    }
}

static inline void func_800F80CC_ovl04_rand(u8* obj) {
    s32 a;
    s32 b;

    *(s16*)(obj + 0x40) = D_80098118[func_8002B5B4(0x1E)] >> 7;
    a = func_8002B5B4(0x1E);
    b = func_8002B5B4(0x1E);
    *(s16*)(obj + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    *(s32*)(obj + 0x3C) =
        (s32)D_1F800020.u32s + D_1F800020.u32s[func_8002B5B4(0x1E)];
}

void func_800F80CC_ovl04(u8* obj) {
    switch (((s8*)obj)[2]) {
    case 0: {
        u8* p;

        *(s16*)(obj + 0xA) = 0x3C1;
        *(s16*)(obj + 0xE) = 0x96;
        D_80103090_ovl04 = 0x5F0;
        D_80103092_ovl04 = 0x2B8;
        func_800F80CC_ovl04_spawn(obj, 2);
        func_800F80CC_ovl04_spawn(obj, 3);
        func_800F80CC_ovl04_spawn(obj, 4);
        func_800F80CC_ovl04_spawn(obj, 5);
        func_800F80CC_ovl04_spawn(obj, 6);
        func_800F80CC_ovl04_spawn(obj, 7);
        func_800F80CC_ovl04_spawn(obj, 8);
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x18;
            p[2] = 0;
            *(u8**)(p + 0x50) = obj;
        }
        *(s16*)(obj + 0x42) = 0;
        D_8009A29E = 0;
        func_80016490(5, 4, 0);
        D_800D1C2C = 1;
        func_8001296C(2);
        break;
    }
    case 1: {
        u8* p;

        p = D_800D1C00;
        p[0x27] = 0;
        p[0x2A] = 0;
        p[0x28] = 0;
        p[0x29] = 0;
        p[0x2B] = 0;
        if (((s8*)p)[0x1D] == 2) {
            *(s16*)(obj + 0xA) = 0x77E;
            obj[5] = 1;
            *(s32*)(obj + 0x84) = 0;
            obj[0x8C] = 0;
        } else {
            *(s16*)(obj + 0xA) = 0x1B0;
            if (((s8*)p)[0x2C] != 1) {
                func_80016490(5, 4, 0);
            }
            func_8001296C(2);
        }
        *(s16*)(obj + 0xE) = 0x168;
        D_80103090_ovl04 = 0x5F0;
        D_80103092_ovl04 = 0x2B8;
        *(s16*)(obj + 0x42) = 0;
        *(u8**)(obj + 0x58) = D_80076920;
        *(u8**)(obj + 0x54) = D_80102A78_ovl04;
        func_800F80CC_ovl04_spawn(obj, 2);
        func_800F80CC_ovl04_spawn(obj, 3);
        func_800F80CC_ovl04_spawn(obj, 4);
        func_800F80CC_ovl04_spawn(obj, 5);
        func_800F80CC_ovl04_spawn(obj, 6);
        func_800F80CC_ovl04_spawn(obj, 7);
        func_800F80CC_ovl04_spawn(obj, 8);
        func_800F80CC_ovl04_spawn2(obj);
        D_8009A29E = 0;
        obj[0x15] = 0;
        break;
    }
    case 2:
        obj[0x5C] = 0x7F;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 0x22;
        *(u8**)(obj + 0x58) = D_80076920;
        *(u8**)(obj + 0x54) = D_80102A7C_ovl04;
        *(u8**)(obj + 0x50) = D_80102A80_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        func_800171E8(obj, 0);
        obj[0x93] = 0x30;
        *(s16*)(obj + 0x88) = 0x18;
        *(s16*)(obj + 0x8A) = 2;
        break;
    case 3:
        obj[0x5C] = 0x50;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 5;
        *(u8**)(obj + 0x58) = D_800755C0;
        *(u8**)(obj + 0x54) = D_80102A84_ovl04;
        *(u8**)(obj + 0x50) = D_80102A88_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        func_800171E8(obj, 1);
        *(s16*)(obj + 0x88) = 0x14;
        *(s16*)(obj + 0x8A) = -0x3E;
        obj[0x92] = 1;
        break;
    case 4:
        obj[0x5C] = 0x50;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 5;
        *(u8**)(obj + 0x58) = D_800755C0;
        *(u8**)(obj + 0x54) = D_80102A8C_ovl04;
        *(u8**)(obj + 0x50) = D_80102A90_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        func_800171E8(obj, 2);
        *(s16*)(obj + 0x88) = 0x22;
        *(s16*)(obj + 0x8A) = 0x15;
        obj[0x92] = 2;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        obj[0x5C] = 0x10;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 4;
        *(u8**)(obj + 0x58) = D_800750C0;
        *(u8**)(obj + 0x54) = D_80102A94_ovl04;
        *(u8**)(obj + 0x50) = D_80102A98_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        if (((s8*)obj)[2] == 5) {
            *(s16*)(obj + 0x88) = 0x30;
            *(s16*)(obj + 0x8A) = -0x48;
            obj[0x92] = 1;
            obj[0x93] = 1;
            func_800171E8(obj, 3);
        } else if (((s8*)obj)[2] == 6) {
            *(s16*)(obj + 0x88) = 0x40;
            *(s16*)(obj + 0x8A) = -0x20;
            obj[0x92] = 1;
            obj[0x93] = 2;
            func_800171E8(obj, 4);
        } else if (((s8*)obj)[2] == 7) {
            *(s16*)(obj + 0x88) = 0x39;
            *(s16*)(obj + 0x8A) = 0x2A;
            obj[0x92] = 2;
            obj[0x93] = 4;
            func_800171E8(obj, 5);
        } else {
            *(s16*)(obj + 0x88) = 0x22;
            *(s16*)(obj + 0x8A) = 0x4B;
            obj[0x92] = 2;
            obj[0x93] = 8;
            func_800171E8(obj, 6);
        }
        break;
    case 9: {
        u8* p;
        u8* q;

        p = D_800D1C00;
        p[0x27] = 0;
        p[0x2A] = 0;
        p[0x28] = 0;
        p[0x29] = 0;
        p[0x2B] = 0;
        q = D_8009A1F8;
        *(s32*)(obj + 0x84) = 0;
        obj[0x8C] = 0;
        obj[0x90] = 0x40;
        obj[0x91] = 0x40;
        *(s16*)(obj + 0xA) = *(u16*)(q + 0xA) + 0x180;
        *(s16*)(obj + 0xE) = *(u16*)(q + 0xE) + 0x58;
        D_80103090_ovl04 = 0x240;
        D_80103092_ovl04 = 0x298;
        *(s16*)(obj + 0x42) = 0;
        func_800F80CC_ovl04_spawn(obj, 0xA);
        func_800F80CC_ovl04_spawn(obj, 0xB);
        func_800F80CC_ovl04_spawn(obj, 0xC);
        func_800F80CC_ovl04_spawn(obj, 0xD);
        func_800F80CC_ovl04_spawn(obj, 0xE);
        func_800F80CC_ovl04_spawn(obj, 0xF);
        func_800F80CC_ovl04_spawn2(obj);
        q[0xA6] = 0;
        func_80016490(2, 0x13, obj);
        func_8001296C(2);
        obj[0x8D] = 0;
        obj[0x15] = 0;
        break;
    }
    case 10:
        obj[0x5C] = 0x40;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 5;
        *(u8**)(obj + 0x58) = D_80076920;
        *(u8**)(obj + 0x54) = D_80102AA4_ovl04;
        *(u8**)(obj + 0x50) = D_80102AA8_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        func_800171E8(obj, 0x2C);
        break;
    case 11:
        obj[0x5C] = 0x40;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 5;
        *(u8**)(obj + 0x58) = D_80076920;
        *(u8**)(obj + 0x54) = D_80102AAC_ovl04;
        *(u8**)(obj + 0x50) = D_80102AB0_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        func_800171E8(obj, 0x2D);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        obj[0x5C] = 0x10;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 4;
        *(u8**)(obj + 0x58) = D_800750C0;
        *(u8**)(obj + 0x54) = D_80102AB4_ovl04;
        *(u8**)(obj + 0x50) = D_80102AB8_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        if (((s8*)obj)[2] == 0xC) {
            *(s16*)(obj + 0x88) = -0x25;
            *(s16*)(obj + 0x8A) = -0x28;
            obj[0x92] = 1;
            obj[0x93] = 0x11;
            func_800171E8(obj, 0xD);
        } else if (((s8*)obj)[2] == 0xD) {
            *(s16*)(obj + 0x88) = -0x20;
            *(s16*)(obj + 0x8A) = 0;
            obj[0x92] = 1;
            obj[0x93] = 0x22;
            func_800171E8(obj, 0xE);
        } else if (((s8*)obj)[2] == 0xE) {
            *(s16*)(obj + 0x88) = -0x20;
            *(s16*)(obj + 0x8A) = 0x48;
            obj[0x92] = 2;
            obj[0x93] = 0x44;
            func_800171E8(obj, 0xF);
        } else {
            *(s16*)(obj + 0x88) = -0x31;
            *(s16*)(obj + 0x8A) = 0x68;
            obj[0x92] = 2;
            ((s8*)obj)[0x93] = -0x78;
            func_800171E8(obj, 0x10);
        }
        break;
    case 16: {
        D_800D1C00[0x27] = 0;
        D_800D1C00[0x2A] = 0;
        D_800D1C00[0x28] = 0;
        D_800D1C00[0x29] = 0;
        D_800D1C00[0x2B] = 0;
        obj[0x5C] = 0x7F;
        obj[0x60] = 6;
        *(s16*)(obj + 0xA) = 0x1360;
        *(s16*)(obj + 0xE) = 0x500;
        D_80103090_ovl04 = 0x420;
        D_80103092_ovl04 = 0x250;
        *(s16*)(obj + 0x42) = 0;
        *(u8**)(obj + 0x58) = D_80076920;
        *(u8**)(obj + 0x54) = D_80102ABC_ovl04;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 5;
        func_800F80CC_ovl04_rand(obj);
        func_800F80CC_ovl04_spawn(obj, 0x11);
        func_800F80CC_ovl04_spawn(obj, 0x12);
        func_800F80CC_ovl04_spawn(obj, 0x13);
        func_800F80CC_ovl04_spawn(obj, 0x14);
        func_800F80CC_ovl04_spawn(obj, 0x15);
        func_800F80CC_ovl04_spawn(obj, 0x16);
        func_800F80CC_ovl04_spawn(obj, 0x17);
        func_800F80CC_ovl04_spawn2(obj);
        D_8009A29E = 0;
        func_80016490(2, 0x13, obj);
        func_8001296C(2);
        obj[0x8D] = 0;
        obj[0x15] = 0;
        break;
    }
    case 17:
        obj[0x5C] = 0x7F;
        obj[0x60] = 6;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 0x22;
        *(u8**)(obj + 0x58) = D_80076920;
        *(u8**)(obj + 0x54) = D_80102AC0_ovl04;
        *(u8**)(obj + 0x50) = D_80102AC4_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        func_800171E8(obj, 0x16);
        break;
    case 18:
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 0x22;
        *(u8**)(obj + 0x58) = D_800755C0;
        *(u8**)(obj + 0x54) = D_80102AC8_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        func_800171E8(obj, 0x14);
        *(s16*)(obj + 0x88) = -0x1C;
        *(s16*)(obj + 0x8A) = -4;
        break;
    case 19:
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 0x22;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        *(s16*)(obj + 0x88) = 0x14;
        *(s16*)(obj + 0x8A) = -0x26;
        func_800171E8(obj, 0x15);
        break;
    case 20:
    case 21:
    case 22:
    case 23:
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x30) = D_8010295C_ovl04;
        obj[0x16] = 0x22;
        *(u8**)(obj + 0x58) = D_800750C0;
        *(u8**)(obj + 0x54) = D_80102ACC_ovl04;
        func_800F80CC_ovl04_rand(obj);
        obj[0x15] = 0;
        obj[5] = 2;
        if (((s8*)obj)[2] == 0x14) {
            *(s16*)(obj + 0x88) = -0x5E;
            *(s16*)(obj + 0x8A) = 0x20;
            obj[0x93] = 1;
            func_800171E8(obj, 0x18);
        } else if (((s8*)obj)[2] == 0x15) {
            *(s16*)(obj + 0x88) = -0x24;
            *(s16*)(obj + 0x8A) = 0x20;
            obj[0x93] = 2;
            func_800171E8(obj, 0x19);
        } else if (((s8*)obj)[2] == 0x16) {
            *(s16*)(obj + 0x88) = 0x16;
            *(s16*)(obj + 0x8A) = 0x20;
            obj[0x93] = 4;
            func_800171E8(obj, 0x1A);
        } else {
            *(s16*)(obj + 0x88) = 0x4F;
            *(s16*)(obj + 0x8A) = 0x20;
            obj[0x93] = 8;
            func_800171E8(obj, 0x1B);
        }
        break;
    }
    obj[4]++;
}
