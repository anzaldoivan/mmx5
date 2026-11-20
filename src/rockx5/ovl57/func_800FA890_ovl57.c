#include "types.h"

void func_800FA890_ovl57(u8* arg0) {
    *(s16*)(arg0 + 4) += 1;
    if (*(s16*)(arg0 + 4) >= 0x14) {
        arg0[1]++;
    }
}
