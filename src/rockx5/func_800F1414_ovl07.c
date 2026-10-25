#include "types.h"

extern int func_8002D6FC();

void func_800F1414_ovl07(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x7C);
    p[0x98]--;
    func_8002D6FC();
}
