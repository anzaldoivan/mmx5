#include "types.h"

void func_8003CE10(u8* arg0) {
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    if (*(s8*)(arg0 + 0x8C) > 0) {
        *(s8*)(arg0 + 0x8C) = -1;
    }
}
