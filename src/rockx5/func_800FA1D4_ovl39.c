#include "types.h"
#include "addr.h"

extern s32 func_80031DD0(u8* a0);
extern u8* func_8002D0E4(void);
extern void func_800FCE1C_ovl39(void* arg0, u8 arg1);
extern u8 D_8009A1F8[];
extern u8 D_800FE804_ovl39[];
extern void* D_800FEB74_ovl39[];
extern u8 D_800766A0[];
extern u8 D_8009A11A;
extern u8 D_80074EE0[];

void func_800FA1D4_ovl39(u8* a0) {
    s32 r;
    u8* p;
    u8* d;
    u8 t;

    d = D_8009A1F8;
    if (*(s16*)(d + 0x96) != 0x100) {
        *(u8**)(a0 + 0x54) = D_800FE804_ovl39;
    } else {
        *(u8**)(a0 + 0x54) = 0;
    }
    if (D_1F80004C.bytes[0x8F] != 0) {
        if (!(D_1F80004C.bytes[0x8F] & 1)) {
            u8* d1 = D_8009A1F8;
            *(s16*)(d1 + 0x94) = 4;
        } else {
            u8* d2 = D_8009A1F8;
            *(s16*)(d2 + 0x94) = 0;
        }
        {
            u8* d3 = D_8009A1F8;
            d3[0xA0] = 1;
        }
        if (--D_1F80004C.bytes[0x8F] == 0) {
            *(u8**)(a0 + 0x58) = D_800766A0;
        }
    }
    ((void (*)(u8*))D_800FEB74_ovl39[(s8)a0[5]])(a0);
    if (D_1F80004C.bytes[0x85] == 0) {
        return;
    }
    r = func_80031DD0(a0);
    if (r < 0) {
        D_8009A11A = 1;
        a0[4] = 2;
        a0[5] = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        *(u8**)(a0 + 0x58) = D_80074EE0;
        if ((u32)(r - 0x19) < 2) {
            D_1F80004C.bytes[0x84] = 2;
        } else {
            D_1F80004C.bytes[0x84] = 0x1E;
        }
        if (r == 8 || r == 0x11 || r == 0x2C) {
            if (D_1F80004C.bytes[0x8F] == 0) {
                D_1F80004C.bytes[0x8F] = 0x78;
                *(u8**)(a0 + 0x58) = D_80074EE0;
                p = func_8002D0E4();
                if (p != 0) {
                    u8 k;
                    p[0] = 0x61;
                    p[1] = 0x15;
                    p[2] = 6;
                    *(u16*)(p + 0x40) = *(u16*)(a0 + 0x40);
                    *(s32*)(p + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(p + 0x3C) = *(s32*)(a0 + 0x3C);
                    *(u16*)(p + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
                    k = a0[0x15];
                    *(s16*)(p + 0xA) = 0x1228;
                    *(s16*)(p + 0xE) = 0x798;
                    *(u8**)(p + 0x50) = a0;
                    p[0x15] = k;
                }
            }
        }
    }
    t = D_1F80004C.bytes[0x84];
    if (t != 0) {
        D_1F80004C.bytes[0x84] = t + 0xFF;
        if (t & 2) {
            u8* d4 = D_8009A1F8;
            *(s16*)(d4 + 0x96) = 0x200;
            d4[0xA0] = 1;
        } else {
            func_800FCE1C_ovl39(a0, D_1F80004C.bytes[0x88]);
        }
        if (D_1F80004C.bytes[0x84] == 0) {
            func_800FCE1C_ovl39(a0, D_1F80004C.bytes[0x88]);
            *(u8**)(a0 + 0x58) = D_800766A0;
        }
    }
}
