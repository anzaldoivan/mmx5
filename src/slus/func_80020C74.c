#include "types.h"

extern void func_8002C50C(void);
extern s32 func_80013458(void);

void func_80020C74(u8* arg0) {
    func_8002C50C();
    func_80013458();
    arg0[0] = 8;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
}
