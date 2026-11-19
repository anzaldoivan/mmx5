#include "types.h"

void func_800EEE6C_ovl21(u8* arg0) {
    if (*(s16*)(arg0 + 6) < 0x50) {
        *(s16*)(arg0 + 6) += 1;
        return;
    }
    arg0[1] += 1;
}
