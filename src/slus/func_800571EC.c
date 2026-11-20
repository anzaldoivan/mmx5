#include "types.h"
#include "mmx5/globals.h"

void func_800571EC(u8* a0) {
    D_800E95A8[a0[0x1B]][5]++;
    a0[0x1B]++;
    if (a0[0x1B] == 22) {
        *(u16*)(a0 + 0x18) = 60;
        a0[5]++;
    }
}
