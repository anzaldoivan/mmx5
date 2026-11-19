#include "types.h"

s32 poll_rock_bin_read();

void func_800F6B64_ovl18(u8* arg0) {
    if (poll_rock_bin_read() != 0) {
        arg0[4]++;
    }
}
