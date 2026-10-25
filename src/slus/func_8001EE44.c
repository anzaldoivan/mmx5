#include "types.h"

extern void func_80017D88(void);
extern void func_800177B0(s32, s32);
extern void func_8002C1C8(void);
extern void func_8002C50C(void);
extern u8* func_8002D27C(void);
extern void func_80013288(s32);
extern s8 D_8009A426;
extern u8 D_80070EF4[];

void func_8001EE44(u8* a0) {
    u8* obj;
    u8 i;

    D_8009A426 = 0;
    func_80017D88();
    func_800177B0(0x14, 0x7F);
    func_8002C1C8();
    func_8002C50C();
    for (i = 0; i < 6; i++) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x13;
            obj[2] = D_80070EF4[i];
        }
    }
    func_80013288(8);
    *(u16*)(a0 + 4) = 0;
    a0[1]++;
}
