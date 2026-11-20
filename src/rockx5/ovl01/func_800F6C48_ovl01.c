#include "types.h"
#include "mmx5/system.h"
#include "addr.h"

void func_800F6C48_ovl01(void) {
    D_1F80004C.bytes[0x84] = random_byte() & 3;
}
