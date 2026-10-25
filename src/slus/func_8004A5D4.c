#include "types.h"

void func_8004A5D4(u8* arg0) {
    *(s16*)(arg0 + 0x8C) += 1;
    if (*(s16*)(arg0 + 0x8C) >= 40) {
        arg0[5]++;
    }
}
