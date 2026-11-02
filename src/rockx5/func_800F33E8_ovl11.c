#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8* func_8002D210();
extern u8 D_8009A0B4;
extern u32* D_80098118;
extern u8 D_800F9C0C_ovl11[];
extern u8 D_800767E0[];
extern s8 D_800D1C28[];
extern u16 D_800F9C38_ovl11[];
extern u16 D_800F9C30_ovl11[];
extern u8 D_800F9BA4_ovl11[];
extern u8 D_800F9BAC_ovl11[];
extern u8 D_800F9BA8_ovl11[];
extern u8 D_800F9BB0_ovl11[];
extern u8 D_800F9BB4_ovl11[];

void func_800F33E8_ovl11(u8* p) {
    s32 a;
    s32 b;
    s32 i;
    u8* q;

    p[4] = 1;
    p[5] = 2;
    p[6] = 0;
    p[7] = 0;
    p[0] = 0x41;
    p[0x15] = 0;
    p[0x14] = D_8009A0B4;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x93)] >> 7;
    a = func_8002B5B4(0x93);
    *(s32*)(p + 0x3C) = (s32)D_1F800020.u32s + D_1F800020.u32s[a];
    a = func_8002B5B4(0x93);
    b = func_8002B5B4(0x93);
    *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) | ((((b + 6) / 4) + 0x1E0) << 6);
    p[0x16] = 0x22;
    *(u8**)(p + 0x30) = D_800F9C0C_ovl11;
    p[0x60] = 0x7F;
    p[0x61] = 0;
    p[0x75] = 1;
    p[0xA2] = 1;
    p[0x65] = 0;
    *(u8**)(p + 0x58) = D_800767E0;
    p[0x84] = 0;
    p[0x85] = 0;
    switch ((s8)p[2]) {
    case 0:
        D_800D1C28[1] = 0;
        for (i = 0; i < 3; i++) {
            q = func_8002D210();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x12;
                *(u16*)(q + 0xA) = D_800F9C30_ovl11[i];
                *(u16*)(q + 0xE) = D_800F9C38_ovl11[i];
                q[2] = i + 3;
                *(u8**)(q + 0x7C) = p;
            }
        }
        p[5] = 2;
        p[0x47] = 9;
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x24) = -0x8000;
        *(u8**)(p + 0x68) = D_800F9BA4_ovl11;
        *(u8**)(p + 0x54) = D_800F9BAC_ovl11;
        p[0x82] = 0;
        break;
    case 1:
        D_800D1C28[1] = 2;
        p[5] = 3;
        *(s32*)(p + 0x20) = 0x8000;
        *(s32*)(p + 0x24) = 0x8000;
        p[0x47] = 10;
        *(u8**)(p + 0x68) = D_800F9BA8_ovl11;
        *(u8**)(p + 0x54) = D_800F9BB0_ovl11;
        break;
    case 2:
        D_800D1C28[1] = 3;
        p[5] = 4;
        *(s32*)(p + 0x24) = 0x8000;
        p[0x47] = 9;
        *(s32*)(p + 0x20) = 0;
        *(u8**)(p + 0x68) = D_800F9BA4_ovl11;
        *(u8**)(p + 0x54) = D_800F9BB4_ovl11;
        p[0x82] = 0;
        *(s16*)(p + 0x80) = 0;
        break;
    case 3:
    case 4:
    case 5:
        p[0x16] = 0x23;
        p[5] = 9;
        if ((s8)p[2] == 5) {
            p[0x47] = 0xB;
        } else {
            p[0x47] = 0xC;
        }
        *(u8**)(p + 0x68) = D_800F9BA4_ovl11;
        *(u8**)(p + 0x54) = D_800F9BB4_ovl11;
        break;
    }
}
