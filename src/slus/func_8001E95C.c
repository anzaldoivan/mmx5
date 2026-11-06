#include "types.h"

extern void func_80013288(s32);
extern void func_80017668(void);
extern void func_80020950(void);
extern void func_80020A3C(void);
extern void func_80023500(void);
extern void func_80027238(void);
extern void func_800272B4(void);
extern void func_8002906C(void);
extern void func_8002A440(void);
extern void func_8002A4E4(void);
extern void func_8002A554(void);
extern void func_8002ACC4(void);
extern void func_8002B474(void);
extern void func_8002B520(void);
extern void func_8002C50C(void);
extern void func_8002D004(void);
extern u8* func_8002D27C(void);
extern void func_8003BAC8(void);

void func_8001E95C(u8* arg0) {
    u32 i;
    u8* p;

    func_8002C50C();
    func_8002D004();
    func_80017668();
    func_80023500();
    func_8002906C();
    func_8002ACC4();
    func_8002A440();
    func_8002A4E4();
    func_8002A554();
    func_8003BAC8();
    func_8002B474();
    func_8002B520();
    func_80027238();
    func_80020950();
    for (i = 2; i < 5; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x12;
            p[2] = i;
        }
    }
    func_80020A3C();
    arg0[2] = 0;
    arg0[1]++;
    func_80013288(8);
    func_800272B4();
}
