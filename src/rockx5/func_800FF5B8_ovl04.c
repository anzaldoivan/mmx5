#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D33C(u8* p, s32 backward);
extern u16 D_80102EE8_ovl04[][2];
extern u8 D_80074E40[];
extern u8 D_80102EC8_ovl04[];
extern u8 D_80102ECC_ovl04[];
extern u8 D_80102ED0_ovl04[];
extern u8 D_80074DA0[];
extern u8 D_80102ED4_ovl04[];
extern u8 D_80102EDC_ovl04[];
extern s16 D_8009A206;

void func_800FF5B8_ovl04(u8* obj) {
    u8* p;
    u8* q;
    s32 st;

    p = *(u8**)(obj + 0x7C);
    st = (s8)obj[2];
    *(u16*)(obj + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(p + 0x3C);
    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    obj[0x16] = 0;
    obj[0x14] = 0;
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    obj[3] = 1;
    switch (st) {
    case 0:
        *(u16*)(obj + 0xA) += D_80102EE8_ovl04[(s8)p[2] - 5][0];
        *(u16*)(obj + 0xE) += D_80102EE8_ovl04[(s8)p[2] - 5][1];
        *(u8**)(obj + 0x58) = D_80074E40;
        *(u8**)(obj + 0x50) = D_80102EC8_ovl04;
        *(u8**)(obj + 0x54) = D_80102ECC_ovl04;
        obj[0x60] = 3;
        obj[0x15] = 0;
        func_800171E8(obj, 7);
        *(s32*)(obj + 0x20) <<= 5;
        *(s32*)(obj + 0x24) <<= 5;
        q = func_8002D33C(0, 0);
        if (q != 0) {
            *(u8**)(q + 0x50) = obj;
            q[0] = 0x41;
            q[1] = 0xB;
            q[2] = 0;
        }
        break;
    case 1:
        func_80016490(2, 0x12, p);
        *(u8**)(obj + 0x50) = D_80102ED0_ovl04;
        obj[0x60] = 6;
        obj[0x15] = 0;
        func_800171E8(obj, 0xC);
        *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) + 0xDA;
        *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
        *(u16*)(obj + 0x88) = 0;
        obj[0x16] = 0x32;
        break;
    case 2:
        *(u8**)(obj + 0x58) = D_80074DA0;
        *(u8**)(obj + 0x50) = D_80102ED4_ovl04;
        *(u8**)(obj + 0x54) = D_80102EDC_ovl04;
        obj[0x60] = 4;
        obj[0x5C] = 4;
        obj[0x15] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        func_800171E8(obj, 0x12);
        *(s32*)(obj + 0x24) = *(s16*)(obj + 0xE) - D_8009A206;
        obj[0x16] = 0x20;
        obj[5] = 2;
        break;
    case 3:
        *(u8**)(obj + 0x50) = D_80102ED0_ovl04;
        obj[0x60] = 6;
        obj[0x15] = 0;
        func_800171E8(obj, 0x32);
        *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) + 0x20;
        *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
        obj[3] = 0;
        obj[0x16] = 0x31;
        break;
    case 4:
        *(u8**)(obj + 0x58) = D_80074E40;
        *(u8**)(obj + 0x50) = D_80102EC8_ovl04;
        *(u8**)(obj + 0x54) = D_80102ECC_ovl04;
        obj[0x60] = 3;
        obj[0x15] = 0;
        *(u16*)(obj + 0xA) += 8;
        *(u16*)(obj + 0xE) -= 0x10;
        func_800171E8(obj, 7);
        *(u16*)(obj + 0x88) = 0x1E;
        *(s32*)(obj + 0x20) <<= 5;
        *(s32*)(obj + 0x24) <<= 5;
        q = func_8002D33C(0, 0);
        if (q != 0) {
            *(u8**)(q + 0x50) = obj;
            q[0] = 0x41;
            q[1] = 0xB;
            q[2] = 0;
        }
        break;
    }
    obj[4]++;
}
