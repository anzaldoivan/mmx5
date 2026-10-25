#include "types.h"

void func_80032CEC();

void func_80051EE0(u8* a0) {
    if (--a0[0x3B] == 0xFF) {
        a0[4]++;
        func_80032CEC();
    }
}
