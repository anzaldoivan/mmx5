#include "types.h"

extern int func_8002D7A0();

void func_800F16C4_ovl05(u8* arg0) {
    if (--*(s16*)(arg0 + 0x88) == 0) {
        func_8002D7A0();
    }
}
