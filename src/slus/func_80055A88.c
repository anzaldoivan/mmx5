#include "types.h"

extern void func_8003D2C4(void);

void func_80055A88(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        func_8003D2C4();
        arg0[5]++;
    }
}
