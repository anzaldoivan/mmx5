#include "types.h"

extern void func_8001E668(u8*);
extern void func_80017668(void);
extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_800177B0(s32, s32);
extern u8* func_8002D27C(void);
extern void func_80013288(s32);
extern u8 D_8009A1F8[];
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
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    D_8009A1F8[3] = 0;
    D_8009A1F8[0x57] = 0;
    D_8009A1F8[0xAB] = 1;
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
