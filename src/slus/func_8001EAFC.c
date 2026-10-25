#include "types.h"

extern void func_80027288(void);
extern void func_80017D88(void);
extern void func_80016D54(s32, s32);
extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8002CF20(void);
extern void func_800272B4(void);
extern u8 D_8009A420[];

void func_8001EAFC(u8* obj) {
    u8* p = D_8009A420;

    if (((s8*)p)[4] == 0) {
        obj[0xD] = 1;
        p[6] = 0;
        func_80027288();
        func_80017D88();
        func_80016D54(0xFF, 0);
        func_8002C50C();
        func_8002D004();
        func_8002CF20();
        obj[0] = 3;
        obj[1] = 0;
    } else {
        func_800272B4();
    }
}
