#include "types.h"

void func_800EF170_ovl21(u8* arg0) {
    *(s16*)(arg0 + 4) += 1;
    if (*(s16*)(arg0 + 4) >= 0x78) {
        arg0[1]++;
    }
}
