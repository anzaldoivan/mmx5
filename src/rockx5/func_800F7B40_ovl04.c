#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern s32 func_8002DF78(void);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8010295C_ovl04[];
extern u32* D_80098118;
extern u8 D_8009A1F8[];
extern u8 D_8009A0A0[];

void func_800F7B40_ovl04(u8* obj) {
    s32 a;
    s32 b;
    s32 c;
    s32 t;
    s32 k;
    s32 m;
    u8* p0;
    u8* p11;

    *(u8**)(obj + 0x30) = D_8010295C_ovl04;
    *(s16*)(obj + 0x40) = D_80098118[func_8002B5B4(0x1E)] >> 7;
    a = func_8002B5B4(0x1E);
    b = func_8002B5B4(0x1E);
    *(s16*)(obj + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    c = func_8002B5B4(0x1E);
    *(s32*)(obj + 0x3C) = (s32)D_1F800020.u32s + D_1F800020.u32s[c];
    *(u16*)(obj + 0x54) = 0xFFFF;
    obj[0x14] = 0;
    obj[0x16] = 0;
    obj[0x15] = 0;
    switch (*(s8*)(obj + 2)) {
    case 0:
        t = func_8002DF78() * 2;
        p0 = D_8009A1F8;
        *(s16*)(obj + 0xA) = *(u16*)(p0 + 0xA) + t % 320;
        *(s16*)(obj + 0xE) = *(u16*)(p0 + 0xE) + 0xF0;
        *(s32*)(obj + 0x20) = 0;
        if ((u8)((u32)func_8002DF78() % 3) == 2) {
            func_800171E8(obj, 0x30);
            *(s32*)(obj + 0x24) = 0x20000;
        } else {
            *(s32*)(obj + 0x24) = 0x10000;
            func_800171E8(obj, 0x31);
        }
        *(s32*)(obj + 0x24) += func_8002DF78() << 7;
        obj[5] = 0;
        break;
    case 1:
    case 2:
        *(s32*)(obj + 0x20) = 0xFFFC0000;
        *(s32*)(obj + 0x28) = -0x8000;
        *(s32*)(obj + 0x24) = 0x8000;
        *(s32*)(obj + 0x2C) = 0;
        if (*(s8*)(obj + 2) == 1) {
            func_800171E8(obj, (u8)((u32)func_8002DF78() % 12) + 0x20);
        } else {
            func_800171E8(obj, 0x2F);
        }
        obj[5] = 1;
        break;
    case 3:
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x10000;
        *(s32*)(obj + 0x2C) = 0x1000;
        func_800171E8(obj, (u8)((u32)func_8002DF78() % 12) + 0x20);
        obj[5] = 2;
        break;
    case 4:
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x10000;
        func_800171E8(obj, 0x2F);
        obj[5] = 0;
        break;
    case 5:
        *(s32*)(obj + 0x20) = 0x10000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x10000;
        *(s32*)(obj + 0x2C) = 0x1000;
        func_800171E8(obj, (u8)((u32)func_8002DF78() % 12) + 0x20);
        obj[5] = 2;
        break;
    case 6:
    case 8:
        do {
            *(s32*)(obj + 0x24) = 0x20000;
            k = 0x1000;
        } while (0); // !FAKE: fence keeps the 0x1000 li beside the 0x24 store
        m = 2;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = k;
        obj[5] = m;
        func_800171E8(obj, (u8)((u32)func_8002DF78() % 12) + 0x20);
        break;
    case 7:
        if (func_8002DF78() & 4) {
            if ((u8)((u32)func_8002DF78() % 3) == 2) {
                func_800171E8(obj, 0x30);
                *(s32*)(obj + 0x24) = 0x20000;
            } else {
                func_800171E8(obj, 0x31);
                *(s32*)(obj + 0x24) = 0x10000;
            }
            *(s32*)(obj + 0x24) += func_8002DF78() << 7;
            obj[5] = 3;
        } else {
            *(s32*)(obj + 0x24) = 0x10000;
            func_800171E8(obj, 0x2F);
            obj[5] = 3;
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        break;
    case 9:
    case 10:
        break;
    case 11:
        p11 = D_8009A0A0;
        *(s16*)(obj + 0xE) = *(u16*)(p11 + 0xE) - 0x12;
        if (p11[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(u16*)(p11 + 0xA) - 0xC;
        } else {
            *(s16*)(obj + 0xA) = *(u16*)(p11 + 0xA) + 0xC;
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x10000;
        func_800171E8(obj, 0x33);
        obj[5] = 0;
        break;
    }
    obj[4]++;
}
