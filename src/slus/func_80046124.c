#include "types.h"

extern int func_8002D6FC();
extern u8 D_8009A0A0[];

void func_80046124(u8* arg0) {
    *(s32*)(arg0 + 0x50) = 0;
    if (((s8*)arg0)[1] != 0x15) {
        D_8009A0A0[0x98]--;
    }
    func_8002D6FC();
}
