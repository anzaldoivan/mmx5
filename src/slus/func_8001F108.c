#include "types.h"

extern void func_8001E668(void);
extern void func_8002CF20(void);
extern s32 func_80013674(void);
extern void func_80017668(void);
extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_80013288(s32);
extern u8 D_800D1C00[];
extern u8 D_8009A1F8[];

void func_8001F108(u8* a0) {
    u8* p;
    u8* q;

    a0[0xD] = 2;
    func_8001E668();
    func_8002CF20();
    p = D_800D1C00;
    p[0xC] = 0xE;
    p[0xD] = 0;
    func_80013674();
    func_80017668();
    func_8002C50C();
    func_8002D004();
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    q = D_8009A1F8;
    q[3] = 1;
    q[0x57] = 0;
    q[0xAB] = 0;
    func_80013288(8);
    a0[1]++;
}
