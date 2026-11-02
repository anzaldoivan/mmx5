#include "types.h"

extern void func_80013288(s32);
extern void func_80013524(void);
extern void func_80014684(s32, s32, s32);
extern void func_800157D4(void);
extern void func_80017668(void);
extern void func_80020950(void);
extern void func_80020A3C(void);
extern s32 func_80020F44(void);
extern s32 func_80027238(void);
extern void func_8002906C(void);
extern void func_8002A440(void);
extern void func_8002A4E4(void);
extern void func_8002A554(void);
extern void func_8002ACC4(void);
extern void func_8002B474(void);
extern void func_8002B520(void);
extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8003BAC8(void);
extern u8 D_8006FADD;
extern u8 D_80091C38[];
extern s32 D_80091D54;
extern s16 D_8009A41A;
extern s32 D_8009A758;
extern u8 D_800D1598;
extern s8 D_800D1C1D;

void func_800203F0(u8* arg0) {
    u32 i;
    u8* p;
    u8* q;

    if (func_80020F44() != 0 && D_800D1598 != D_800D1C1D) {
        func_80013524();
    }
    i = 0;
    if (*(s8*)(arg0 + 0xC) == 0xC) {
        if ((*(s32*)(arg0 + 0x1C) & 0xFFFF00) == 0xFF0A00) {
            func_80014684(0x57, 4, D_8009A758);
            func_800157D4();
        }
    }
    for (i = 0, q = arg0 + 0x26; i < 8; i++) {
        q[i] = 0;
    }
    p = D_80091C38;
    p[0xC] = 0;
    *(s16*)(p + 0x10) = 0;
    func_8002C50C();
    func_8002D004();
    func_80017668();
    func_8002906C();
    func_8002ACC4();
    func_8002A440();
    func_8002A4E4();
    func_8002A554();
    func_8003BAC8();
    func_8002B474();
    func_8002B520();
    arg0[0x1C] = 1;
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    arg0[0x10] = 0;
    arg0[0x11] = 0;
    arg0[0x12] = 0;
    arg0[0x13] = 0;
    arg0[0x14] = 0;
    arg0[0x15] = 0;
    arg0[0x16] = 0;
    arg0[0x17] = 0;
    arg0[0x18] = 0;
    arg0[0x19] = 0;
    arg0[0x1A] = 0;
    arg0[0xF] = 0;
    arg0[0x7B] = D_8006FADD;
    func_80027238();
    func_80020950();
    if (arg0[0x43] != 0) {
        arg0[0x43] = 0;
    } else {
        func_80020A3C();
    }
    func_80013288(8);
    arg0[0] = 0xA;
    D_80091D54 = 1;
    D_8009A41A = 0x3C;
}
