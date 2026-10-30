#include "types.h"

extern void func_80017248();

void func_800F5B04_ovl18(u8* arg0) {
    func_80017248();
    if (*(s8*)(arg0 + 0x45) == 1) {
        arg0[3] = 0;
        arg0[6] = 0;
    }
}
