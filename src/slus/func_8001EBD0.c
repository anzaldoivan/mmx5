#include "types.h"

extern void func_80027288(void);
extern void func_80017D88(void);
extern void func_80016D54(s32, s32);
extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_80013BD4(void);
extern void func_800176B0(void);
extern u8* func_8002D27C(void);
extern void func_80013288(s32);

void func_8001EBD0(u8* arg0) {
    u8* p;

    arg0[0xD] = 1;
    func_80027288();
    func_80017D88();
    func_80016D54(0xFF, 0);
    func_8002C50C();
    func_8002D004();
    func_80013BD4();
    func_800176B0();
    p = func_8002D27C();
    if (p != 0) {
        p[1] = 0x15;
        p[0] = 1;
        p[0x47] = 0;
        p[2] = 0;
        *(s16*)(p + 0xA) = 0x80;
        *(s16*)(p + 0xE) = 0x78;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[1] = 0x15;
        p[0] = 1;
        p[0x47] = 1;
        p[2] = 0;
        *(s16*)(p + 0xA) = 0x120;
        *(s16*)(p + 0xE) = 0x78;
    }
    *(s16*)(arg0 + 4) = 0x12C;
    func_80013288(8);
    arg0[1]++;
}
