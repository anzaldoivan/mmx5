#include "types.h"

extern u8 D_800C9328[];
extern Ctl D_8009A420;
extern void func_80012E0C(s32, void (*)(void));
extern void func_8001303C(void);

void func_80013288(s8 arg) {
    u8* p = D_800C9328;

    p[0x2D] = 0;
    p[0x2E] = 0;
    p[0x2F] = 0;
    p[0xDD] = 0;
    p[0xDE] = 0;
    p[0xDF] = 0;
    if (D_8009A420.busy == 0) {
        D_8009A420.busy = 1;
        D_8009A420.arg = arg;
        func_80012E0C(2, func_8001303C);
    }
}
