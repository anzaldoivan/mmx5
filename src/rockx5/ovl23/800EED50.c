#include "types.h"
#include "mmx5/globals.h"

extern void func_80017668(void);
extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_800177B0(s32, s32);
extern void func_80013288(s32);
extern s32 D_800EF894_ovl23[];

void func_800EED50_ovl23(u8* arg0) {
    u8* q;
    u8* p;
    u8 i;

    for (i = 0; i < 16; i++) {
        q = arg0 + 0x26;
        q[i] = 0;
    }
    func_8001E668(q);
    func_80017668();
    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    D_8009A1F8.u[3] = 0;
    D_8009A1F8.u[0x57] = 0;
    D_8009A1F8.u[0xAB] = 1;
    func_800177B0(0x15, 0x70);
    for (i = 2; i < 8; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1C;
            p[2] = i;
        }
    }
    arg0[0x4A] = 0;
    func_80013288(8);
    arg0[0x44] = 0;
    arg0[2] = 0;
    *(s16*)(arg0 + 0xA) = 3;
    arg0[1]++;
    D_800EF894_ovl23[0] = 0;
    D_800EF894_ovl23[1] = 0;
}

extern s8 D_8009A424;

void func_800EEE74_ovl23(u8* a0) {
    s32 i;
    u8* p;

    if (D_8009A424 == 0) {
        for (i = 0; i < 2; i++) {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x1C;
                p[2] = i;
            }
        }
        a0[2] = 0;
        a0[1]++;
        ((s32(*)())func_8002C218)();
        *(s16*)(a0 + 4) = 2;
    }
}

extern void func_8002C1C8(void);

void func_800EEF0C_ovl23(u8* arg0) {
    u16 n = *(u16*)(arg0 + 4);

    if (*(s16*)(arg0 + 4) != 0) {
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        *(u16*)(arg0 + 4) = n - 1;
    } else {
        arg0[1]++;
        func_8002C1C8();
    }
}

extern signed char D_8009A424;

void func_800EEF78_ovl23(u8* a0) {
    if (D_8009A424 == 0) {
        ((s32(*)())func_8001E668)();
        D_8009A1F8.u[3] = 0;
        D_8009A1F8.u[0x57] = 0;
        D_8009A1F8.u[0xAB] = 0;
        ((s32(*)())func_8002C50C)();
        if (a0[0x79] == 0) {
            a0[0] = 0x13;
            a0[0x1D] = 0;
        } else {
            a0[0xC] = 0x16;
            a0[0xD] = 0;
            a0[0] = 7;
        }
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
    }
}
