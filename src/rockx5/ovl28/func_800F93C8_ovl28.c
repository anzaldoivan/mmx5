#include "types.h"

void func_800F93C8_ovl28(u8* arg0) {
    s32 v;

    v = arg0[0x85] - 1;
    arg0[0x85] = v;
    if ((v & 0xFF) == 0xFF) {
        arg0[6]++;
    }
}
